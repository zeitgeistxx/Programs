#include<iostream>
#include<vector>
using namespace std;


bool isCycle(int src, vector<vector<int>> &adj, vector<int> &visited, vector<int> &stack){
    stack[src] = 1;
    if(!visited[src]){
        visited[src] = 1;
        for(auto i: adj[src]){
            if(!visited[i] and isCycle(i, adj, visited, stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }
    stack[src] = false;
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
    }

    bool cycle = false;
    vector<int> stack(n, 0);
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++){
        if(!visited[i] and isCycle(i, adj, visited, stack)){
            cycle = true;
        }
    }

        if (cycle)
            cout << "Cycle is present" << endl;
        else
            cout << "Cycle isn't present" << endl;
}