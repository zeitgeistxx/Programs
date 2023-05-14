#include <iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

int x[10], ans = 0;

bool Place(int k, int i){
    for (int j = 1; j < k; j++) if (x[j] == i or abs(j - k) == abs(x[j] - i)) return false;
    return true;
}

void nQueen(int k, int n){
    for (int i = 1; i <= n; i++)
    {
        if(Place(k, i)){
            x[k] = i;
            if(k == n){
                ans++;
                for (int j = 1; j <= n; j++) cout << x[j] << " ";
                cout << endl;
            }
            else nQueen(k + 1, n);
        }
    }
}

int main(){
    int n;

    cout << "Enter no. of Queens -> ";
    cin >> n;

    if(n == 2 or n == 3){
        cout << "No Possible Solution" << endl;
        return -99999;
    }

    nQueen(1, n);

    cout << "Possible Solutions -> " << ans;
}