#include<iostream>
#include<iomanip>
#include<climits>
using namespace std;

int n, w[10][10];

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

int dist[10], parent[10], sptSet[10]; // shortest path tree set (sptSet)

int minKey(){
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < n; i++)
    {
		if(!sptSet[i])
		{
			if(min > dist[i])
			{
                min = dist[i];
                minIndex = i;
            }
		}
	}
	return minIndex;
}

void dijkstra(int r)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = 9999;
        parent[i] = -1;
        sptSet[i] = 0;
    }
    dist[r] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = minKey();
        sptSet[u] = 1;
        for (int v = 0; v < n; v++)
        {
			if(w[u][v] != 0){
				if(dist[u] + w[u][v] < dist[v] && !sptSet[v])
				{
                    dist[v] = dist[u] + w[u][v];
                    parent[v] = u;
                }
			}
		}
	}
}

void showPath(int dest)
{
	if(dest == -1) return;
    showPath(parent[dest]);
    cout << setw(3) << char(dest + 'A');
}

int main()
{
	readGraph();
	showGraph();

	dijkstra(0);

    cout << "\n\n";
    showPath('F'-'A');

    cout << "\n\nCost = " << dist['F' - 'A'];
}
