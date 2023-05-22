#include<iostream>
#include<iomanip>
#include<climits>
using namespace std;

struct Edge{
    int v1, v2, weight;
};

int noE, noV, n, w[10][10];
Edge edge[noE];
int dist[20], pred[20];

void readGraph(){

    FILE* fp = fopen("./graph.txt", "r");
    if (fp == NULL)
    {
        cout << "No such file." << endl;
        return;
    }

    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &w[i][j]);
        }
    }
    fclose(fp);
}

void showGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << setw(3) << w[i][j];
        cout << endl;
    }
}

void BellmanFord(int src){
    for (int i = 0; i < noV; i++)
    {
        dist[i] = 999;
        pred[i] = -1;
    }
    dist[src] = 0;
    for (int i = 1; i <= noV - 1; i++)
    {
        for (int j = 0; j < noE; j++)
        {
            int u = edge[j].v1;
            int v = edge[j].v2;
            if(dist[u] + w[u][v] < dist[v]){
                dist[v] = dist[u] + w[u][v];
                pred[v] = u;
            }
        }
    }
}

void displayPath(int i){
    if(i == -1) return;
    displayPath(pred[i]);
    cout << char(i + 'A') << setw(3);
}



int main()
{
    cout << "Enter no. of vertices: ";
    cin >> noV;
    cout << "\nEnter no. of edges: ";
    cin >> noE;

	readGraph();
	showGraph();

    BellmanFord(0);
    displayPath(3);

    cout << "\nCost = " << dist[3] << endl;
}
