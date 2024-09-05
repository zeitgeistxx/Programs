#include <iostream>
#include <iomanip>
#define size 10
using namespace std;

class Queue
{
    int front, rear;
    int arr[size];

public:
    Queue()
    {
        front = rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void insert(int);
    void del();
    int peek();
    void display();
};

bool Queue::isEmpty()
{
    return front == rear;
}

bool Queue::isFull()
{
    return rear == size - 1;
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

int Queue::peek()
{
    return arr[front + 1];
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
}

int n, adjM[10][10] = {0}, visited[10] = {0}; // n = no. of vertices

void readGraph()
{

    FILE *fp = fopen("adjM.txt", "r");
    if (fp == NULL)
    {
        cout << "No such file." << endl;
        return;
    }

    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &adjM[i][j]);
        }
    }
    fclose(fp);
}

int main()
{

    readGraph();

    Queue q;

    q.insert(0);
    visited[0] = 1;

    cout << "BFS traversal is given below ->" << endl;
    while (!q.isEmpty())
    {
        int node = q.peek();
        q.del();

        cout << char(node + 'A') << setw(5);

        for (int i = 0; i < n; i++)
        {
            if (adjM[node][i] && !visited[i])
            {
                visited[i] = 1;
                q.insert(i);
            }
        }
    }
}