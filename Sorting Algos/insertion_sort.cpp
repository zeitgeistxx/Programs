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
    //insert an element from unsorted array to its correct position in sorted array
    //assume the first element of the array is sorted, then start from the next element
    for(int i=1; i<n; i++){
        int current = arr[i];
        //compare starts from the preceeding element
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    cout<<"The sorted array is:"<<" ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}