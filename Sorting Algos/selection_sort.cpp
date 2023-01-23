#include<iostream>
using namespace std;

int main(){
    int n;
    cout <<"Enter array size: ";
    cin>>n;

    int arr[n];
    cout <<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //for each element,compare it with all preceeding elements,if any smaller value is found swap them

    int comparison = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            comparison++;
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout<<"The sorted array is:"<<" ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout << "\nComparison needed " << comparison;
}