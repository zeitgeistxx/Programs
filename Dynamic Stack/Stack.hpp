#include <iostream>
#include<climits>
using namespace std;


template<typename T>
class Stack
{
    T *data;
    int top;
    int capacity, deafaultCapacity = 6;

public:
    Stack()
    {
        capacity = deafaultCapacity;
        data = new T[capacity];
        top = -1;
    }
    Stack(int size){
        capacity = size;
        data = new T[capacity];
        top = -1;
    }


    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return capacity == top + 1;
    }

    void push(T element){
        if(isFull()){
            cout << "Stack is Full" << endl;
            return;
        }
        top++;
        data[top] = element;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[top];
    }

    void display(){
        if(!isEmpty()){
            for (int i = 0; i <= top; i++){
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
};



// bool Stack<T>::isEmpty(){
//     return top == -1;
// }