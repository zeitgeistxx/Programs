#include <iostream>
#include<iomanip>
#include<climits>
using namespace std;

int n, G[10][10];

void readGraph(){
    FILE* fp = fopen("graph.txt", "r");
    if (fp == NULL){
        cout << "No such file." << endl;
        return;
    }

    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fscanf(fp, "%d", &G[i][j]);
        }
    }
    fclose(fp);
}

void showGraph(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cout << setw(3) << G[i][j];
        cout << endl;
    }
}


int weight[10], parent[10], MSTset[10];

int ExtractMin(){
    int minWeight = INT_MAX, minIndex = -1;
    for (int i = 0; i < n; i++){
        if (!MSTset[i]){
            if (minWeight > weight[i]){
                minWeight = weight[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}


// We have to give a source to find its adjacent least weighted path
void Prims(int src){
    for (int i = 0; i < n; i++){
        weight[i] = INT_MAX;
        parent[i] = -1;
        MSTset[i] = 0;
    }
    weight[src] = 0;
 
    for (int i = 0; i < n; i++){
        int minEdge = ExtractMin();
        MSTset[minEdge] = 1;

        for (int j = 0; j < n; j++){
            if (G[minEdge][j] != 0){
                if (weight[j] > G[minEdge][j] && !MSTset[j]){
                    weight[j] = G[minEdge][j];
                    parent[j] = minEdge;
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