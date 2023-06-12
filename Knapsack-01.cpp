#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Bag{
    int profit, weight;
};

void Knapsack(int m, int n){
    Bag b[n + 1];

    for (int i = 1; i <= n; i++){
        cout << "Number " << i << " bag ->" << endl;

        cout << "Enter profit : ";
        cin >> b[i].profit;

        cout << "Enter Weight : ";
        cin >> b[i].weight;
    }

    int Table[n + 1][m + 1];

    for (int i = 0; i <= m; i++) Table[0][i] = 0;
    for (int i = 0; i <= n; i++) Table[i][0] = 0;

    for (int i = 1; i <= n; i++){
        for (int w = 1; w <= m; w++){
            if(b[i].weight > w){
                Table[i][w] = Table[i-1][w];
            }
            else{
                Table[i][w] = max(Table[i - 1][w], b[i].profit + Table[i - 1][w - b[i].weight]);
            }
        }
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            cout << setw(4) << Table[i][j];
        }
        cout << endl;
    }
}

int main(){
    int m, n;
    cout << "Enter Knapsack capacity and no. of bags -> ";
    cin >> m >> n;

    Knapsack(m, n);
}