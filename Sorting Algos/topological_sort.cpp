#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, e;
    cout << "Enter no. of nodes and edges -> ";
    cin >> n >> e;

    int count = 0;
    vector<vector<int>> adj_list(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        count++;
        int x = q.front();
        q.pop();
        cout << x << " ";

        for(auto it: adj_list[x]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
}



// If a cycle is present in the graph, then topological sort will not be possible