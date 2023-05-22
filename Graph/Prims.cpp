#include <iostream>
#include<iomanip>
#include<climits>
using namespace std;

int n, G[10][10];

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
            fscanf(fp, "%d", &G[i][j]);
        }
    }
    fclose(fp);
}

void showGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << setw(3) << G[i][j];
        cout << endl;
    }
}


int key[10], parent[10], MSTset[10];

int minKey(){
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < n; i++){
        if (MSTset[i] == 0){
            if (min > key[i]){
                min = key[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}

void Prims(int r){
    for (int i = 0; i < n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        MSTset[i] = 0;
    }
    key[r] = 0;

    for (int i = 0; i < n; i++){
        int u = minKey();
        MSTset[u] = 1;

        for (int v = 0; v < n; v++){
            if (G[u][v] != 0){
                if (!MSTset[v] && key[v] > G[u][v]){
                    key[v] = G[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void showTree(){
    for (int i = 0; i < n; i++){ 
        if (parent[i] != -1) cout << char(parent[i] + 'A') << " -> " << char(i + 'A') << " : " << G[parent[i]][i] << endl;
    }
}



int main()
{
    readGraph();
    showGraph();
    Prims(0);
    showTree();
}