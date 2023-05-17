#include <iostream>
#include<iomanip>
using namespace std;

int n, w[10][10];

void readGraph(){

    FILE* fp = fopen("graph.txt", "r");
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


int key[10], parent[10], MSTset[10];

int minKey()
{
    int min = 9999, minIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (MSTset[i] == 0)
        {
            if (min > key[i])
            {
                min = key[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}

void Prims(int r)
{
    for (int i = 0; i < n; i++)
    {
        key[i] = 9999;
        parent[i] = -1;
        MSTset[i] = 0;
    }

    key[r] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = minKey();
        MSTset[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (w[u][v] != 0)
            {
                if (MSTset[v] == 0 && key[v] > w[u][v])
                {
                    key[v] = w[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void showTree()
{
    for (int i = 0; i < n; i++){ 
        if (parent[i] != -1) cout << char(parent[i]+'A') << " -> " << char(i+'A') << " : " << w[parent[i]][i] << endl;
    }
}



int main()
{
    readGraph();
    showGraph();
    Prims(0);
    showTree();
}