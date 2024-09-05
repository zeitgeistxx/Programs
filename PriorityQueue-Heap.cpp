#include <iostream>
#include <climits>
using namespace std;

void maxHeap(int a[], int m, int n)
{
    int j = 2 * m;
    int key = a[m];
    while (j <= n)
    {
        if (j < n and a[j + 1] > a[j])
            j++;
        if (key > a[j])
            break;
        else if (key <= a[j])
        {
            a[j / 2] = a[j];
            j *= 2;
        }
    }
    a[j / 2] = key;
    return;
}

void build_maxHeap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        maxHeap(a, i, n);
}

void minHeap(int a[], int m, int n)
{
    int j = 2 * m;
    int key = a[m];
    while (j <= n)
    {
        if (j < n && a[j + 1] < a[j])
            j++;
        if (key < a[j])
            break;
        else if (key >= a[j])
        {
            a[j / 2] = a[j];
            j *= 2;
        }
    }
    a[j / 2] = key;
    return;
}

void build_minHeap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        minHeap(a, i, n);
}

int n, A[30], heapCapacity = 30, heapSize;

int getMin()
{
    if (heapSize == 0)
        return INT_MIN;
    return A[1];
}

/* deletes and returns min element */
int extractMin()
{
    if (heapSize == 0)
        return INT_MIN;
    int min = A[1];
    A[1] = A[heapSize];
    heapSize--;
    n--;
    minHeap(A, 1, heapSize);
    return min;
}

void decreaseKey(int i, int newVal)
{
    A[i] = newVal;
    while (i > 1 and A[i] < A[i / 2])
    {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

void deleteKey(int i)
{
    if (i <= 0 or i > heapSize)
    {
        cout << "Incorrect operation" << endl;
        return;
    }
    decreaseKey(i, INT_MIN);
    extractMin();
}

int main()
{

    cout << "enter no of elements of array -> ";
    cin >> n;
    heapSize = n;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    // build_maxHeap(a, n);
    build_minHeap(A, n);

    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    // cout << getMin() << endl;
    // cout << extractMin() << endl;
    deleteKey(2);

    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
}