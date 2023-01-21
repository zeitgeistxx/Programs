#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Qlist
{

	Node *front, *rear;

public:
	Qlist()
	{
		front = rear = NULL;
	}
	bool isEmpty();
	void insert(int);
	void del();
	void display();
};

bool Qlist::isEmpty()
{
	if (front == NULL && rear == NULL)
		return true;
	return false;
}

void Qlist::insert(int item)
{
	Node *curr = new Node;
	if (curr == NULL)
	{
		cout << "Heap Full" << endl;
		return;
	}
	curr->data = item;
	curr->next = NULL;
	if (rear == NULL)
	{
		front = rear = curr;
		return;
	}
	rear->next = curr;
	rear = curr;
}

void Qlist::del()
{
	Node *temp = front;
	front = front->next;
	delete temp;
	temp = NULL;
}

void Qlist::display()
{
	if (!isEmpty())
	{
		Node *temp = front;
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
	Qlist ql;
	int choice, item;
	while (true)
	{
		cout << "\n\n";
		cout << "1.EMPTY" << endl;
		cout << "2.PUSH" << endl;
		cout << "3.POP" << endl;
		cout << "4.DISPLAY" << endl;
		cout << "Enter choice ->";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (ql.isEmpty() == 0)
				cout << "False" << endl;
			else
				cout << "True" << endl;
			break;

		case 2:
			cout << "Enter an item ->";
			cin >> item;
			ql.insert(item);
			break;

		case 3:
			ql.del();
			break;

		case 4:
			cout << "The Queue ->";
			ql.display();
			break;

		default:
			cout << "Invalid Choice" << endl;
			exit(0);
		}
	}
}
