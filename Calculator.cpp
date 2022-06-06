#include<iostream>
using namespace std;

int main(){
    float n1,n2,result;
    char op;

    cout<<"Enter first number: ";
    cin >> n1;
    cout<<"Enter operator: ";
    cin >> op;
    cout<<"Enter second number: ";
    cin >> n2;

    switch(op){
        case '+':
            cout<<n1<<" + "<<n2<<" = "<<n1+n2<<endl;
            break;
        case '-': 
            cout<<n1<<" - "<<n2<<" = "<<n1-n2<<endl;
            break;
        case '*': 
            cout<<n1<<" * "<<n2<<" = "<<n1*n2<<endl;
            break;
        case '/': 
            cout<<n1<<" / "<<n2<<" = "<<n1/n2<<endl;
            break;
        default:
            printf("Invalid operator");

    }
    return 0;

}