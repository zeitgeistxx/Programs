#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	int priority; // lower value indiactes higher priority
	Node *next;
};

class Plist
{
	Node *head;

public:
	Plist()
	{
		head = NULL;
	}
	bool isEmpty();
	void insert(int, int);
	void del();
	void display();
};

bool Plist::isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}

void Plist::insert(int item, int p)
{
	Node *curr = new Node;
	curr->data = item;
	curr->priority = p;
	curr->next = NULL;

	Node *temp = head;
	if (isEmpty())
	{
		head = curr;
	}
	else if (head->priority > p)
	{
		// Insert new node before head
		curr->next = head;
		head = curr;
	}
	else
	{
		// Traverse the list to find a positon to insert the new node
		while (temp->next != NULL && temp->next->priority <= p)
		{
			temp = temp->next;
		}

		// Either at the end of the list or required position
		curr->next = temp->next;
		temp->next = curr;
	}
}

void Plist::del()
{
	if (isEmpty())
	{
		cout << "List Empty" << endl;
		return;
	}
	Node *temp = head;
	head = head->next;
	delete temp;
	temp = NULL;
}

void Plist::display()
{
	if (!isEmpty())
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " - " << temp->priority << "  ";
			temp = temp->next;
		}
	}
	return;
}

int main()
{
	Plist pl;
	int choice, item, priority;
	while (true)
	{
		cout << "\n\n";
		cout << "Press 1 to check if Priority Queue is empty" << endl;
		cout << "Press 2 to push an item to Priority Queue" << endl;
		cout << "Press 3 to pop an item from Priority Queue" << endl;
		cout << "Press 4 to display the Priority Queue" << endl;
		cout << "Enter choice ->";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (pl.isEmpty() == 0)
				cout << "False" << endl;
			else
				cout << "True" << endl;
			break;

		case 2:
			cout << "Enter item and its priority :";
			cin >> item >> priority;
			pl.insert(item, priority);
			break;

		case 3:
			pl.del();
			break;

		case 4:
			cout << "The Priority Queue ->";
			pl.display();
			break;

		default:
			cout << "Invalid Choice" << endl;
			exit(0);
		}
	}
}
