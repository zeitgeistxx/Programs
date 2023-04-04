#include<iostream>
#include<iomanip>
using namespace std;


void FractionalKnapsack(int m, int n){
    float p[n], w[n], x[n];
    x[n] = {0};

    cout << "Enter Profits -> ";
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    cout << "Enter Weights -> ";
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int i = 1; i <= n; i++){
        if(w[i] > m){
            x[i] = m / w[i];
            break;
        }
        x[i] = 1;
        m = m - w[i];
    }

    cout << "The fractions are -> ";
    for (int i = 1; i <= n; i++)
        cout << setprecision(1) << x[i] << " ";
}


int main(){
    int m, n;
    cout << "Enter Knapsack capacity and no. of elements -> ";
    cin >> m >> n;

    FractionalKnapsack(m, n);
}