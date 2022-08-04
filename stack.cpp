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
    int x = arr[top];
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
    cout << "\n\n\n";
}

int main()
{
    class Stack s;
    int item;

    while (true)
    {
        cout << "Press 1 to check if Stack is Full" << endl;
        cout << "Press 2 to check if Stack is Empty" << endl;
        cout << "Press 3 to push an item to Stack" << endl;
        cout << "Press 4 to pop top item from Stack" << endl;
        cout << "Press 5 to peek into Stack" << endl;
        cout << "Press 6 to Display the Stack" << endl;
        cout << "Choose an operation ->" << endl;

        int y;
        cin >> y;
        switch (y)
        {
        case 1:
            if (s.isFull() == 0)
                cout << "False" << endl;
            else
                cout << "True" << endl;
            break;

        case 2:
            if (s.isEmpty() == 0)
                cout << "False" << endl;
            else
                cout << "True" << endl;
            break;

        case 3:
            cout << "Enter an item to push :";
            cin >> item;
            s.push(item);
            break;

        case 4:
            s.pop();
            break;

        case 5:
            cout << "The top element " << s.peek() << endl;
            break;

        case 6:
            cout << "The Stack ->";
            s.display();
            break;

        default:
            cout << "Invalid Operation" << endl;
            exit(0);
        }
    }
}