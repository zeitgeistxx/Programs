#include<iostream>
#include<iomanip>
#include<climits>
using namespace std;

int n, w[10][10];

void readGraph(){

    FILE* fp = fopen("./graph.txt", "r");
    if (fp == NULL){
        cout << "No such file." << endl;
        return;
    }

    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fscanf(fp, "%d", &w[i][j]);
        }
    }
    fclose(fp);
}

void showGraph(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cout << setw(3) << w[i][j];
        cout << endl;
    }
}


// Single source shortest path, for directed and undirected Graph
int dist[10], parent[10], SPTset[10]; // shortest path tree set (SPTset)

int ExtractMin(){
    int minDist = INT_MAX, minIndex = -1;
    for (int i = 0; i < n; i++){
		if(!SPTset[i]){
			if(minDist > dist[i]){
                minDist = dist[i];
                minIndex = i;
            }
		}
	}
	return minIndex;
}


// Greedy approach
void Dijkstra(int r){
    for (int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        parent[i] = -1;
        SPTset[i] = 0;
    }
    dist[r] = 0;
    
    for (int i = 0; i < n; i++){
        int u = ExtractMin();
        SPTset[u] = 1;

        for (int v = 0; v < n; v++){
			if(w[u][v] != 0){
				if(dist[u] + w[u][v] < dist[v] && !SPTset[v])
				{
                    dist[v] = dist[u] + w[u][v];
                    parent[v] = u;
                }
			}
		}
	}
}

void showPath(int dest){
	if(dest == -1) return;
    showPath(parent[dest]);
    cout << setw(3) << char(dest + 'A');
}

int main(){
	readGraph();
	showGraph();

	Dijkstra(0);

    cout << "\n\n";
    showPath('F'-'A');

    cout << "\n\nCost = " << dist['F' - 'A'];
}
