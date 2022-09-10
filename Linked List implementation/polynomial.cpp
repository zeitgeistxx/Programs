#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int coef;
	int exp;
	Node *next;
};

class Poly
{

public:
	Node *head;
	Poly()
	{
		head = NULL;
	}
	int isEmpty();
	void createPoly(int, int);
	void addPoly(Node *, Node *);
	void display();
};

int Poly::isEmpty()
{
	if (head == NULL)
		return 1;
	return 0;
}

void Poly::createPoly(int c, int e)
{
	int key = 0;
	Node *curr = new Node;
	curr->next = NULL;
	curr->coef = c;
	curr->exp = e;
	if (head == NULL) // Empty list
	{
		head = curr;
		return;
	}
	Node *temp = head;
	if (temp->next == NULL && e == temp->exp)
	{
		temp->coef = c + temp->coef;
		key = 1;
	}
	
	while (temp->next != NULL)
	{
		if (e == temp->exp)
		{
			temp->coef = c + temp->coef;
			key = 1;
			break;
		}
		else
		{
			temp = temp->next;
			key = 0;
		}
	}
	if (key == 0)
		temp->next = curr;
}

void Poly::display()
{
	if (!isEmpty())
	{
		Node *p = head;
		while (p->next != NULL)
		{
			cout << p->coef << "x^" << p->exp;
			if (p->next->coef >= 0)
				cout << "+";
			p = p->next;
		}
		cout << p->coef << "x^" << p->exp;
	}
}

void Poly::addPoly(Node *p1, Node *p2)
{
	while (p1 != NULL && p2 != NULL)
	{
		static int c, e;
		if (p1->exp > p2->exp)
		{
			c = p1->coef;
			e = p1->exp;
			p1 = p1->next;
		}

		else if (p1->exp < p2->exp)
		{
			c = p2->coef;
			e = p2->exp;
			p2 = p2->next;
		}

		else
		{
			c = p1->coef + p2->coef;
			e = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
		}

		while (p1 != NULL && p2 == NULL)
		{
			createPoly(p1->coef, p1->exp);
			p1 = p1->next;
		}

		while (p2 != NULL && p1 == NULL)
		{
			createPoly(p2->coef, p2->exp);
			p2 = p2->next;
		}

		createPoly(c, e);
	}
}

int main()
{
	Poly p, p1, p2;
	int c, e, first_choice;
	char second_choice;

	while (true)
	{
		cout << "\n\n";
		cout << "Press 1 to create polynomial" << endl;
		cout << "Press 2 to add two polynomials" << endl;
		cout << "Press 3 to display polynomial" << endl;
		cout << "Enter Choice ->";
		cin >> first_choice;

		switch (first_choice)
		{
		case 1:
			cout << "Press 'a' to enter first poly or Press 'b' to enter second poly :";
			cin >> second_choice;
			switch (second_choice)
			{
			case 'a':
				cout << "Enter coefficient and exponent ->";
				cin >> c >> e;
				p1.createPoly(c, e);
				break;

			case 'b':
				cout << "Enter coefficient and exponent ->";
				cin >> c >> e;
				p2.createPoly(c, e);
				break;
			}
			break;

		case 2:
			p.addPoly(p1.head, p2.head);
			break;

		case 3:
			cout << "Press 'a' to display first poly or Press 'b' to display second poly or 'c' to display the added poly:";
			cin >> second_choice;
			switch (second_choice)
			{
			case 'a':
				cout << "The First Poly ->";
				p1.display();
				break;

			case 'b':
				cout << "The Second poly ->";
				p2.display();
				break;

			case 'c':
				cout << "The Resultant Poly ->";
				p.display();
				break;
			}
			break;

		default:
			cout << "Invalid Choice" << endl;
			exit(0);
		}
	}
}
