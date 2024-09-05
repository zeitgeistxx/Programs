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
    void insertSorted(int);
    void display();
    void del(int);
};

int List::isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

void List::insertSorted(int item)
{
    Node *curr = new Node;
    curr->data = item;
    Node *temp = head, *prev;

    // Iterate over the nodes in the list
    while (temp != NULL && temp->data <= item)
    {
        prev = temp;
        temp = temp->next;
    }

    // Insert at beginning
    if (temp == head)
    {
        curr->next = head;
        head = curr;
    }
    // Insert at end
    else if (temp == NULL)
    {
        curr->next = NULL;
        prev->next = curr;
    }

    // Insert at proper position
    else
    {
        curr->next = temp;
        prev->next = curr;
        prev = curr;
    }
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

void List::del(int item)
{
    Node *temp = head, *prev;
    while (temp != NULL && temp->data != item)
    {
        prev = temp;
        temp = temp->next;
    }
    // Outside the list
    if (temp == NULL)
    {
        cout << "Item not found" << endl;
    }
    // At beginning
    else if (temp == head)
    {
        head = head->next;
        delete temp;
        temp = NULL;
        cout << "Item deleted" << endl;
    }
    // Delete any Node
    else
    {
        prev->next = temp->next;
        delete temp;
        temp = NULL;
        cout << "Item deleted" << endl;
    }
}

int main()
{
    List l;
    int item, choice;
    while (true)
    {
        cout << "\n\n";
        cout << "Press 1 to insert an item in List" << endl;
        cout << "Press 2 to display the List" << endl;
        cout << "Press 3 to delete a specific Node" << endl;
        cout << "Enter a choice ->";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter an item ->";
            cin >> item;
            l.insertSorted(item);
            break;

        case 2:
            cout << "The List ->";
            l.display();
            break;

        case 3:
            cout << "Enter an item to delete ->";
            cin >> item;
            l.del(item);
            break;

        default:
            cout << "Invalid Choice" << endl;
            exit(0);
        }
    }
}