#include <iostream>
using namespace std;

int main()
{
    int m, n, p, q;

    cout << "Enter row & coloumn number of first matrix: ";
    cin >> m >> n;
    int a[m][n];

    cout << "Enter row & coloumn number of second matrix: ";
    cin >> p >> q;
    int b[p][q];

    // in order to multiply two matrices coloumn no. of first matrix must be same with row no. of second matrix
    int result[m][q];

    if (n != p)
    {
        cout << "Matrices cannot be multiplied together" << endl;
    }
    else
    {
        cout << "Enter the first matrix: " << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        cout << "Enter the second matrix: " << endl;
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> b[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        { // as the resultant matrix would be of m x q order
            for (int j = 0; j < q; j++)
            {
                int sum = 0;
                // calculate result
                for (int k = 0; k < n; k++)
                { // or k<p
                    sum += a[i][k] * b[k][j];
                }
                result[i][j] = sum;
            }
        }

        // print the result
        cout << "The resultant matrix is:" << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << result[i][j];
                cout << "\t";
            }
            cout << endl;
        }
    }
}