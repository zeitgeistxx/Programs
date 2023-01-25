#include <iostream>
using namespace std;
#define size 10

class Queue
{
    int front, rear;
    int arr[size];

public:
    Queue()
    {
        front = rear = -1;
    }
    bool isFull();
    bool isEmpty();
    void insert(int);
    void del();
    void display();
};

bool Queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}
bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

void Queue::insert(int x)
{
    if (isFull())
    {
        cout << "Queue is Full" << endl;
        return;
    }
    rear++;
    arr[rear] = x;
}

void Queue::del()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    front++;
}

void Queue::display()
{
    if (!isEmpty())
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << "\n\n\n";
}

int main()
{
    Queue q;
    int item;

    while (true)
    {
        cout << "1.FULL" << endl;
        cout << "2.EMPTY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.DISPLAY" << endl;
        cout << "Choose an operation ->" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (q.isFull())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;

        case 2:
            if (q.isEmpty())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;

        case 3:
            cout << "Enter an item to push :";
            cin >> item;
            q.insert(item);
            break;

        case 4:
            q.del();
            break;

        case 5:
            cout << "The Queue ->";
            q.display();
            break;

        default:
            cout << "Invalid Operation" << endl;
            exit(0);
        }
    }
}