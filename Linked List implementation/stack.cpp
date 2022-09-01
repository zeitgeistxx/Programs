#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Slist
{
	Node *top;

public:
	Slist()
	{
		top = NULL;
	}
	bool isEmpty();
	void push(int);
	void pop();
	void display();
};

bool Slist::isEmpty()
{
	if (top == NULL)
		return true;
	return false;
}

void Slist::push(int item)
{
	Node *curr = new Node;

	if (curr == NULL)
	{
		cout << "Heap Full" << endl;
		return;
	}
	curr->data = item;
	curr->next = top;
	top = curr;
}

void Slist::pop()
{
	if (isEmpty())
	{
		cout << "List Empty" << endl;
		return;
	}
	Node *temp;
	temp = top;
	top = top->next;
	delete temp;
	temp = NULL;
}

void Slist::display()
{
	if (!isEmpty())
	{
		Node *temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	return;
}

int main()
{
	Slist sl;
	int choice, item;
	while (true)
	{
		cout << "\n\n";
		cout << "Press 1 to check if Stack is empty" << endl;
		cout << "Press 2 to push an item to stack" << endl;
		cout << "Press 3 to pop an item from stack" << endl;
		cout << "Press 4 to display the stack" << endl;
		cout << "Enter choice ->";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (sl.isEmpty() == 0)
				cout << "False" << endl;
			else
				cout << "True" << endl;
			break;

		case 2:
			cout << "Enter an item ->";
			cin >> item;
			sl.push(item);
			break;

		case 3:
			sl.pop();
			break;

		case 4:
			cout << "The Stack ->";
			sl.display();
			break;

		default:
			cout << "Invalid Choice" << endl;
			exit(0);
		}
	}
}
