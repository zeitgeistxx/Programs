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

    int item;
    cout <<"Enter the element to serach: ";
    cin>>item;

    int key=0;
    for(int i=0; i<n; i++){
        if(arr[i]==item){
            cout<<"Element found at index "<<i<<endl;
            key=1;
        }
    }
    if(key==0){
        cout<<"Element is not found";
    }
}