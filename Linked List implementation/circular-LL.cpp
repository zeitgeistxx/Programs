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
	void delBeg();
	void delEnd();
	void display();
};

Node *createNode(int item)
{
	Node *ptr = new Node;
	ptr->data = item;
	ptr->next = NULL;
}

Node *last()
{
	Node *last = head->next;
	while (last != head)
		last = last->next;
}

int List::isEmpty()
{
	if (last == NULL)
		return 1;
	return 0;
}

void List::insertBeg(int item)
{
	Node *curr = createNode(item);
	if (isEmpty())
	{
		curr->next = curr;
		last = curr;
		return;
	}
	curr->next = last;
	last->next = curr;
	last = curr;
}

void List::insertEnd(int item)
{
	Node *curr = createNode(item);
	if (isEmpty())
	{
		curr->next = curr;
		last = curr;
		return;
	}
	curr->next = last->next;
	last->next = curr;
	last = curr;
}

void List::delBeg()
{
	if (isEmpty())
	{
		cout << "List Empty" << endl;
		return;
	}
	if (last->next == last)
	{
		delete last;
		last = NULL;
		return;
	}
	Node *temp = last->next;
	last->next = temp->next;
	delete temp;
	temp = NULL;
}

void List::delEnd()
{
	if (isEmpty())
	{
		cout << "List Empty" << endl;
		return;
	}
	Node *temp = last->next;
	while (temp->next->next != last)
		temp = temp->next;
	delete temp->next;
	temp->next = last;
}

void List::display()
{
	if (!isEmpty())
	{
		Node *temp = last->next;
		cout << last->data << " ";
		while (temp != last)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}

int main()
{
	List cl;
	int choice, item;
	while (true)
	{
		cout << "\n\n";
		cout << "Press 1 to insert a node at the beginning of the Circular Linked List" << endl;
		cout << "Press 2 to insert a node at the end of the Circular Linked List" << endl;
		cout << "Press 3 to delete a node from the beginning of the Circular Linked List" << endl;
		cout << "Press 4 to delete a node at the end of the Circular Linked List" << endl;
		cout << "Press 5 to Display the Circular Linked List" << endl;
		cout << "Enter choice ->";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter a item ->";
			cin >> item;
			cl.insertBeg(item);
			break;

		case 2:
			cout << "Enter a item ->";
			cin >> item;
			cl.insertEnd(item);
			break;

		case 3:
			cl.delBeg();
			break;

		case 4:
			cl.delEnd();
			break;

		case 5:
			cout << "The list ->";
			cl.display();
			break;

		default:
			cout << "Invalid Choice" << endl;
			exit(0);
		}
	}
}
