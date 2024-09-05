#include <iostream>
#include <climits>
using namespace std;

int getMax(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countingSort(int a[], int n, int pow10)
{
    int count[10] = {0}, output[n];
    for (int i = 0; i < n; i++)
    {
        int digit = (a[i] / pow10) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (a[i] / pow10) % 10;
        output[--count[digit]] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void radixSort(int a[], int n)
{
    int max = getMax(a, n);
    int pow10 = 1;
    while (max != 0)
    {
        countingSort(a, n, pow10);
        pow10 *= 10;
        max /= 10;
    }
}

int main()
{
    int n;
    cout << "Enter array size -> ";
    cin >> n;
    int a[n];

    cout << "Enter elements -> ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    radixSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}