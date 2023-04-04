#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;


// Horae's partition algo
int HoraePartition(int a[], int low, int high){
    int j = low, pivot = a[low];
    for (int i = low + 1; i <= high; i++){
        if(a[i] < pivot){
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j], a[low]);
    return j;
}


// Lomuto's partition algo
int LomutoPartition(int a[], int low, int high){
    int j = low - 1, pivot = a[high];
    for (int i = low; i < high; i++){
        if(a[i] <= pivot){
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[++j], a[high]);
    return j;
}

void QuickSort(int a[], int low, int high){
    if (low < high){
        int pivot = LomutoPartition(a, low, high);
        QuickSort(a, low, pivot - 1);
        QuickSort(a, pivot + 1, high);
    }
}

void RandomizeQuickSort(int a[], int low, int high){
    if(low < high){
        if(high - low + 1 > 5){
            int pos = rand() % (high - low + 1) + low;
            swap(a[low], a[pos]);
        }
        int pivot = LomutoPartition(a, low, high);
        RandomizeQuickSort(a, low, pivot - 1);
        RandomizeQuickSort(a, pivot + 1, high);
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

    RandomizeQuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}