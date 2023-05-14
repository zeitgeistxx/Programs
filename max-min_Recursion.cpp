#include<iostream>
#include<array>
#include<cmath>
using namespace std;

int Max = INT_MIN, Min = INT_MAX;


void MaxMin(int a[], int low, int high){
    int i = low, j = high;
    if(i == j){
        if(a[i] > Max) Max = a[i];
        if(a[i] < Min) Min = a[i];
    }
    else{
        int mid = (low + high) / 2;
        MaxMin(a, low, mid);
        MaxMin(a, mid + 1, high);
    }
}

int main(){

    int a[] = {10, 12, 5, 34, 45, 9, -8};

    MaxMin(a, 0, sizeof(a)/sizeof(int) - 1);

    cout << "Maximum number -> " << Max << endl;
    cout << "Minimum number -> " << Min << endl;
}