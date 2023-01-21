//Generate all the  Binary strings of n bits
#include<iostream>
using namespace std;

char a[5000];

void Binary(int n){
    if(n < 1){
        cout << a << endl;
    }

    else{
        a[n - 1] = '0';
        Binary(n - 1);
        a[n - 1] = '1';
        Binary(n - 1);

    }
}

int main(){
    int n;
    cin >> n;
    Binary(n);
}