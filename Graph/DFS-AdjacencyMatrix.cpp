#include <iostream>
#include <iomanip>
using namespace std;

int n, adjM[10][10] = {0}, visited[10] = {0};

void readGraph()
{
    FILE *fp = fopen("adjM.txt", "r");
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
            fscanf(fp, "%d", &adjM[i][j]);
        }
    }
    fclose(fp);
}

void dfs(int node)
{
    visited[node] = 1;
    cout << char(node + 'A') << setw(5);

    for (int i = 0; i < n; i++)
    {
        if (adjM[node][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{

    readGraph();

    cout << "DFS traversal is given below ->" << endl;
    dfs(0);
}