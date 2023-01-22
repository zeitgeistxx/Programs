#include<iostream>
#include<vector>
using namespace std;


bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, int parent){
    visited[src] = true;
    for(auto i: adj[src]){
        if(i != parent){
            if(visited[i]){
                return true;
            }
            if(!visited[i] and isCycle(i, adj, visited, src)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++){
        if(!visited[i] and isCycle(i, adj, visited, -1)){
            cycle = true;
        }
    }

    if(cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle isn't present" << endl;
}