#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    Node *prev;
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
    void delBeg();
    void delEnd();
    void display();
    void Rdisplay();
};

int List::isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

Node *createNode(int item)
{
    Node *ptr = new Node;
    ptr->data = item;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

void List::insertBeg(int item)
{
    Node *curr = createNode(item);
    if (isEmpty())
        head = curr;
    else
    {
        curr->next = head;
        head->prev = curr;
        head = curr;
    }
}

void List::insertEnd(int item)
{
    Node *curr = createNode(item);
    if (isEmpty())
        head = curr;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = curr;
        curr->prev = temp;
    }
}

void List::delBeg()
{
    if (isEmpty())
    {
        cout << "List Empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void List::delEnd()
{
    if (isEmpty())
    {
        cout << "List Empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
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
}

void List::Rdisplay()
{
    if (!isEmpty())
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
}

int main()
{
    List dl;
    int item, choice;

    while (true)
    {
        cout << "\n\n";
        cout << "Press 1 to insert a node at the beginning" << endl;
        cout << "Press 2 to insert a node at the ending" << endl;
        cout << "Press 3 to delete a node from the beginning" << endl;
        cout << "Press 4 to delete a node from the end" << endl;
        cout << "Press 5 to display the doubly linked list" << endl;
        cout << "Press 6 to reverse display the doubly linked list" << endl;
        cout << "Enter a choice ->";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter an item ->";
            cin >> item;
            dl.insertBeg(item);
            break;

        case 2:
            cout << "Enter an item ->";
            cin >> item;
            dl.insertEnd(item);
            break;

        case 3:
            dl.delBeg();
            break;

        case 4:
            dl.delEnd();
            break;

        case 5:
            cout << "The Doubly Linked List ->";
            dl.display();
            break;

        case 6:
            cout << "The Doubly Linked List in Reverse ->";
            dl.Rdisplay();
            break;

        default:
            cout << "Invalid choice" << endl;
            exit(0);
        }
    }
}