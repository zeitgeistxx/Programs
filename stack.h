#include <iostream>
using namespace std;
#define size 10

class Stack
{
    int arr[size];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isFull();
    bool isEmpty();
    void push(int x);
    void pop();
    int peek();
    void display();
};

bool Stack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    return false;
}
bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack is Full" << endl;
    }
    top++;
    arr[top] = x;
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    top--;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack Empty" << endl;
    }
    int x = arr[top];
    return x;
}

void Stack::display()
{
    if (!isEmpty())
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}