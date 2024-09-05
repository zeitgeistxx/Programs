#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

struct Edge
{
    int v1, v2, weight;
};

int noE = 0, noV, w[10][10], dist[20], pred[20];
Edge x[20];

void readGraph()
{
    FILE *fp = fopen("./graph.txt", "r");
    if (fp == NULL)
    {
        cout << "No such file." << endl;
        return;
    }

    fscanf(fp, "%d", &noV);
    for (int i = 0; i < noV; i++)
    {
        for (int j = 0; j < noV; j++)
        {
            fscanf(fp, "%d", &w[i][j]);
        }
    }
    fclose(fp);
}

void showGraph()
{
    for (int i = 0; i < noV; i++)
    {
        for (int j = 0; j < noV; j++)
            cout << setw(3) << w[i][j];
        cout << endl;
    }
}

void NumOfEdges()
{
    int count;
    for (int i = 0; i < noV; i++)
    {
        for (int j = 0; j < noV; j++)
        {
            if (w[i][j])
                count++;
        }
    }
    noE = count / 2;
}

void MakeEdgeList()
{
    NumOfEdges();
    for (int i = 0; i < noV; i++)
    {
        for (int j = 0; j < noV; j++)
        {
            for (int k = 0; k < noE; k++)
            {
                if (w[i][j])
                {
                    x[k].v1 = i;
                    x[k].v2 = j;
                    x[k].weight = w[i][j];
                }
            }
        }
    }
}

void BellmanFord(int src)
{
    for (int i = 0; i < noV; i++)
    {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    dist[src] = 0;

    for (int i = 1; i <= noV - 1; i++)
    {
        for (int j = 0; j < noE; j++)
        {
            int u = x[j].v1;
            int v = x[j].v2;
            if (dist[u] + w[u][v] < dist[v])
            {
                dist[v] = dist[u] + w[u][v];
                pred[v] = u;
            }
        }
    }
}

void displayPath(int i)
{
    if (i == -1)
        return;
    displayPath(pred[i]);
    cout << char(i + 'A') << setw(3);
}

int main()
{
    readGraph();
    showGraph();
    MakeEdgeList();

    for (int i = 0; i < noE; i++)
    {
        cout << x[i].v1 << " : " << x[i].v2 << " : " << x[i].weight << endl;
    }

    // BellmanFord(0);
    // displayPath(3);

    // cout << "\nCost = " << dist[3] << endl;
}