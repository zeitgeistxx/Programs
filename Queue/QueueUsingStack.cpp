#include "stack.h"

class Queue
{
    Stack s1, s2;

public:
    void enQueue(int item);
    int deQueue();
};

void Queue::enQueue(int item)
{
    while (!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1.push(item);
    while (!s2.isEmpty())
    {
        s1.push(s2.peek());
        s2.pop();
    }
}

int Queue::deQueue()
{
    if (s1.isEmpty())
    {
        cout << "Queue is empty!" << endl;
        exit(0);
    }
    int x = s1.peek();
    s1.pop();
    return x;
}

int main()
{
    class Queue q;
    // q.enQueue(5);
    // q.enQueue(3);
    // q.enQueue(21);
    cout << q.deQueue() << endl;
}