#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    int n, e;
    cout << "Enter no. of nodes and edges -> ";
    cin >> n >> e;

    bool visited[n + 1] = {0};
    vector<int> adjL[n + 1];

    int x, y;
    cout << "Enter the nodes which are connected ->" << endl;
    for (int i = 0; i < e; i++){
        cin >> x >> y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    cout << "BFS traversal is given below ->" << endl;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << endl;

        for(int x: adjL[node]){
            if(!visited[x]){
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}