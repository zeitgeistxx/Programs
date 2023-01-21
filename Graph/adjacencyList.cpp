#include <iostream>
#include <vector>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;


int main()
{

    int n, e;
    cout << "Enter no. of nodes and edges -> ";
    cin >> n >> e;

    vector<int> adjL[n+1]; // create static array of n+1 vectors   

    loop(i,0,e)
    {
        int x, y;
        cin >> x >> y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    cout << "Adjacency List of above graph is given by -> " << endl;

    loop(i,1,n+1){
        cout << i << " -> ";
        for(int x: adjL[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}