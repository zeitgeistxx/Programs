#include <iostream>
using namespace std;

int x[10] = {0}, n = 4, m = 2;

int G[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 1, 0, 1, 0}};

void nextValue(int k)
{
    while (true)
    {
        int j;
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (j = 1; j < k; j++)
        {
            if (G[j][k] == 1 and x[k] == x[j])
                break;
        }
        if (j == k)
            return;
    }
}

int mColoring(int k)
{
    while (true)
    {
        nextValue(k);
        if (x[k] == 0)
            return n;
        if (k == n)
        {
            for (int i = 1; i <= n; i++)
                cout << x[i] << " ";
            cout << endl;
        }
        else
        {
            mColoring(k + 1);
        }
    }
}

int main()
{
    mColoring(1);
}