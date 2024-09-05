#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    int isEmpty();
    void insertBeg(int);
    void insertEnd(int);
    void deleteBeg();
    void deleteEnd();
    void display();
    void search(int);
    void reverse();
};

int List::isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

void List::insertBeg(int item)
{
    Node *curr = new Node;
    curr->data = item;
    curr->next = head;
    head = curr;
}

void List::insertEnd(int item)
{
    Node *curr = new Node;
    curr->data = item;
    curr->next = NULL;
    if (isEmpty())
    {
        head = curr;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = curr;
}

void List::deleteBeg()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void List::deleteEnd()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void List::display()
{
    if (!isEmpty())
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    return;
}

void List::search(int item)
{
    if (!isEmpty())
    {
        int key = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                key = 1;
                break;
            }
            else
                key = 0;
            temp = temp->next;
        }
        if (key == 1)
        {
            cout << "Element is present" << endl;
            return;
        }
        cout << "Element not present" << endl;
    }
}

void List::reverse()
{
    Node *p = head, *q, *r = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    head = r;
}

int main()
{
    List l;
    int choice, item;
    while (true)
    {
        cout << "\n\n";
        cout << "Press 1 to insert a node at the beginning of the list" << endl;
        cout << "Press 2 to insert a node at the end of the list" << endl;
        cout << "Press 3 to delete a node from the beginning of the list" << endl;
        cout << "Press 4 to delete a node at the end of the list" << endl;
        cout << "Press 5 to display the list" << endl;
        cout << "Press 6 to search an element in the list" << endl;
        cout << "Press 7 to reverse the list" << endl;
        cout << "Enter a choice ->";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter an item ->";
            cin >> item;
            l.insertBeg(item);
            break;

        case 2:
            cout << "Enter an item ->";
            cin >> item;
            l.insertEnd(item);
            break;

        case 3:
            l.deleteBeg();
            break;

        case 4:
            l.deleteEnd();
            break;

        case 5:
            cout << "The List ->";
            l.display();
            break;

        case 6:
            cout << "Enter an element to Search ->";
            cin >> item;
            l.search(item);
            break;

        case 7:
            l.reverse();
            break;

        default:
            cout << "Invalid choice" << endl;
            exit(0);
        }
    }
}