#include <iostream>

using namespace std;

void input(int *, int);
void output(int *, int);

bool sequentialSearch(int *arr, int size, int num)
{
    bool flag = false;
    for (int i = 0; i < size && flag == false; i++)
    {
        if (arr[i] == num)
        {
            flag = true;
        }
    }
    return flag;
}

int main()
{
    int size = 0;
    int searchingNumber = 0;
    cout << "Enter the size of the array :";
    cin >> size;
    while (size < 0)
    {
        cout << "Invalid input:Enter the positive size of the array :\n";
        cin >> size;
    }
    int *arr = new int[size];

    input(arr, size);
    output(arr, size);

    cout << "Enter the number that you want to seach in the array:\n";
    cin >> searchingNumber;
    sequentialSearch(arr, size, searchingNumber) ? cout << "Yes " << searchingNumber << " is present in the array " : cout << "No Such " << searchingNumber << " number exist in the array ";

    delete[] arr;
    arr = nullptr;
    return 0;
}
void input(int *arr, int size)
{
    cout << "Enter the numbers elements in the array of size " << size + 1 << " :\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "\n";
}
void output(int *arr, int size)
{
    cout << "The elements in the array :\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\n";
    }
}