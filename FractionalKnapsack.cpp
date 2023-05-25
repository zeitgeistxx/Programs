#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Bag{
    float profit, weight;
};

void FractionalKnapsack(int m, int n){
    Bag b[n];
    float x[n] = {0};

    for (int i = 1; i <= n; i++){
        cout << "Number " << i << " bag ->" << endl;

        cout << "Enter profit : ";
        cin >> b[i].profit;

        cout << "Enter Weight : ";
        cin >> b[i].weight;
    }

    /* Sort in the basis of [profit[i] / weight[i] >= profit[i+1] / weight[i+1]] */
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            if(b[j].profit / b[j].weight > b[i].profit / b[i].weight){
                swap(b[j], b[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (b[i].weight > m){
            x[i] = m / b[i].weight;
            break;
        }
        x[i] = 1;
        m = m - b[i].weight;
    }

    cout << "The fractions are -> ";
    for (int i = 1; i <= n; i++) cout << setprecision(1) << x[i] << " ";
}

int main(){
    int m, n;
    cout << "Enter Knapsack capacity and no. of bags -> ";
    cin >> m >> n;

    FractionalKnapsack(m, n);
}