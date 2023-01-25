#include<iostream>
using namespace std;

int fact(int n, int prod){
    if(n==0 || n==1)
        return prod;
    return fact(n - 1, n * prod);
}


int main(){
    int n;
    cin >> n;
    cout << fact(n, 1) << endl;
}