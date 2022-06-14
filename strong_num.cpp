//if summation of factorial of each digit returns the original number then it is a strong number
#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0 || n==1) {
        return 1;
    }
    else 
        return n * factorial(n-1);
}

int main(){
    int n,strong=0;
    cout << "Enter a number to check whether it is a strong number or not: ";
    cin>>n;
    int original = n;
    while(n!=0){
        int temp = n % 10;
        strong += factorial(temp);
        n/=10;
    }
    if(strong==original) {
        cout<<"Strong number"<<endl;

    }else{
        cout<<"Not Strong number"<<endl;
    }
}