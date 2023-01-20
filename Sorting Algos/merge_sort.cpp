#include <iostream>
#include <vector>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;
	int c[high + 1];

	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j]){
			c[k] = a[i];
			i++;
		}
		else{
			c[k] = a[j];
			j++;
		}
		k++;
	}

	while (i <= mid){
		c[k] = a[i];
		i++;
		k++;
	}
	while (j <= high){
		c[k] = a[j];
		j++;
		k++;
	}

	for (int i = low; i <= high; i++){
		a[i] = c[i];
	}
}

void mergeSort(int a[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main()
{
	int n;
	cout << "Enter array size -> ";
	cin >> n;
	int a[n], c[n];

	cout << "Enter elements -> ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}