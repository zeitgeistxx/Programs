#include <iostream>
#include <iomanip>
using namespace std;

struct Edge
{
    int v1, v2, weight;
};

Edge x[9] = {
    {0, 1, 7}, {1, 2, 6}, {1, 3, 3}, {0, 3, 8}, {2, 3, 4}, {2, 4, 2}, {3, 4, 3}, {2, 5, 5}, {4, 5, 2}};

int noe = sizeof(x) / sizeof(Edge);
void displayGraph()
{
    for (int i = 0; i < noe; i++)
    {
        cout << char(x[i].v1 + 'A') << " -> " << char(x[i].v2 + 'A') << " : " << x[i].weight << endl;
    }
}

void Sort()
{
    for (int i = 0; i < noe - 1; i++)
    {
        for (int j = 0; j < noe - i - 1; j++)
            if (x[j].weight > x[j + 1].weight)
                swap(x[j], x[j + 1]);
    }
}

int parent[100];

// Find parent of i from disjoint set
int find(int i)
{
    while (parent[i] > 0)
        i = parent[i];
    return i;
}

void Union(int i, int j)
{
    int u = find(i), v = find(j);
    parent[v] = u;
}

int treeEdge[100][2], countTreeEdge = 0, nov = 6;

// Greedy approach
void Kruskal()
{
    Sort();
    for (int i = 0; i < nov; i++)
        parent[i] = -1;
    for (int i = 0; i < noe; i++)
    {
        if (find(x[i].v1) != find(x[i].v2))
        {
            treeEdge[countTreeEdge][0] = x[i].v1;
            treeEdge[countTreeEdge++][1] = x[i].v2;
            Union(x[i].v1, x[i].v2);
        }
    }
    countTreeEdge--;
}

void displaySpanningTree()
{
    for (int i = 0; i < countTreeEdge; i++)
        cout << char(treeEdge[i][0] + 'A') << " -> " << char(treeEdge[i][1] + 'A') << endl;
}

int main()
{
    displayGraph();
    Kruskal();
    cout << "\n\n";
    displaySpanningTree();
}