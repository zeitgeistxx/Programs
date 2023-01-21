#include<iostream>
#include<stack>
#include<vector>
using namespace std;

const int N = 1e5 + 2;
vector<int> adjL[N];
bool visited[N] = {0};

void dfs(int node){
    //preorder
    visited[node] = 1;
    cout << node << " ";

    //inorder
    for(int x: adjL[node]){
        if(visited[x]);
        else{
            dfs(x);
        }
    }

    //postorder
}


int main(){
    int n, e;
    cout << "Enter no. of nodes and edges -> ";
    cin >> n >> e;


    int x, y;
    cout << "Enter the nodes which are connected ->" << endl;
    for (int i = 0; i < e; i++){
        cin >> x >> y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    cout << "DFS traversal is given below ->" << endl;
    dfs(1);
}