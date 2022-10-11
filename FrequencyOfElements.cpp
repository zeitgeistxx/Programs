#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    map<int,int> m;
    int n; //Number of elements in array
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int x: arr){
        m[x]++; //main line for solving this problem
    }
    map<int, int> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout<<it->first<<"->"<<it->second<<endl;
    }
    return 0;
}
