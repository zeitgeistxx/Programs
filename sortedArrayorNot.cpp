#include <iostream>
using namespace std;

int isArraySorted(int arr[], int n){
    if(n==1){
        return 1;
    }
    return (arr[n - 1] < arr[n - 2]) ? 0 : isArraySorted(arr, n - 1);
}


int main(){
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    
    if(isArraySorted(a, n)==0){
        cout<<"Not Sorted!"<<endl;
    }
    else{
        cout<<"Sorted!"<<endl;
    }
}