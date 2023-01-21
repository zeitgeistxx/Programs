#include <iostream>
#include <vector>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int main()
{
    int n, e;
    cout << "Enter no. of nodes and edges -> ";
    cin >> n >> e;

    vector<vector<int>> adjM(n + 1, vector<int>(n + 1, 0));

    loop(i, 0, e)
    {
        int x, y;
        cin >> x >> y;

        adjM[x][y] = 1;
        adjM[y][x] = 1;
    }

    cout << "Adjacency Matrix of above graph is given by -> " << endl;

    loop(i, 1, n + 1)
    {
        loop(j, 1, n + 1)
            cout << adjM[i][j] << " ";
        cout << endl;
    }
}