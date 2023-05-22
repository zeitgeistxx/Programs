#include<iostream>
#include<iomanip>
#include<climits>
using namespace std;

int p[20], n;
int M[20][20] = {0}, S[20][20] = {0};


void MatrixChainOrder()
{

    cout << "Number of matrices -> " << --n;

    for (int i = 1; i <= n; i++) M[i][i]=0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(cost < M[i][j]){
                    M[i][j] = cost;
                    S[i][j] = k;
                }
			}
		}
	}

    cout << "\nM-table\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << setw(4) << M[i][j];
        }
        cout << endl;
    }

    cout << "\nS-table\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
			cout << setw(4) << S[i][j];
		}
        cout << endl;
    }
}



void printOptimalParenthesis(int i,int j)
{
	if(i == j) 
        cout << "A " << i;
	else{
        cout << "(";
        printOptimalParenthesis(i, S[i][j]);
        printOptimalParenthesis(S[i][j] + 1, j);
        cout << ")";
	}
}


int main()
{
	cout << "Enter number of sequence of matrices -> ";
    cin >> n;

    cout << "\nEnter dimensions -> " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter d::" << i << " : ";
        cin >> p[i];
    }

	MatrixChainOrder();
	printOptimalParenthesis(1,n);
}
