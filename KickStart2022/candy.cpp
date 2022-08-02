#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll a[n];
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        ll remain = sum % m;
        cout << remain << endl;
    }
}