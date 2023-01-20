#include<iostream>
#include<algorithm>
using namespace std;


int partition(int a[], int low, int high){
    int i = low - 1, pivot = a[high];
    for (int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high){
    if (low < high){
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}



int main(){
    int n;
	cout << "Enter array size -> ";
	cin >> n;
	int a[n];

	cout << "Enter elements -> ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}