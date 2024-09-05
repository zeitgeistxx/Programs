#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	Node *left;
	int lthread;
	int data;
	int rthread;
	Node *right;
};

class Tree
{
public:
	Node *root;
	Tree()
	{
		root = NULL;
	}
	int empty();
	Node *inorderSucc(Node *);
	void inOrder();
	void insert(int);
	void search(int);
};

int Tree::empty()
{
	if (root == NULL)
		return 1;
	return 0;
}

Node *newNode(int key)
{
	Node *ptr = new Node;
	ptr->data = key;
	ptr->lthread = 1;
	ptr->rthread = 1;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

Node *Tree::inorderSucc(Node *r)
{
	if (r == NULL)
		return NULL;
	if (r->right == NULL)
		return NULL;
	r = r->right;
	while (r->lthread != 1)
		r = r->left;
	return r;
}

void Tree::inOrder()
{
	if (empty())
	{
		cout << "Tree is empty" << endl;
		return;
	}
	Node *r = root;
	if (r == NULL)
		return;
	while (r->lthread != 1)
		r = r->left;
	while (r != NULL)
	{
		cout << r->data << " ";
		r = inorderSucc(r);
	}
}

void Tree::insert(int key)
{
	if (empty())
	{
		root = newNode(key);
		return;
	}
	Node *temp = root, *parent;
	while (true)
	{
		parent = temp;
		if (key == temp->data)
		{
			cout << "Duplicate data" << endl;
			return;
		}
		if (key < temp->data)
		{
			if (temp->lthread != 1)
				temp = temp->left;
			else
				break;
		}
		else
		{
			if (temp->rthread != 1)
				temp = temp->right;
			else
				break;
		}
	}

	Node *curr = newNode(key);
	if (key < parent->data)
	{
		curr->left = parent->left;
		parent->left = curr;
		curr->right = parent;
		parent->lthread = 0;
	}
	else
	{
		curr->right = parent->right;
		parent->right = curr;
		curr->left = parent;
		parent->rthread = 0;
	}
}

void Tree::search(int key)
{
	if (empty())
	{
		cout << "Tree is Empty" << endl;
		return;
	}
	Node *temp = root;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			cout << "Item Found" << endl;
			return;
		}
		else if (key < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	cout << "Item not Found" << endl;
}

int main()
{
	int key, choice;
	Tree t;
	while (true)
	{
		cout << "\n\n";
		cout << "1.INSERT" << endl;
		cout << "2.SEARCH" << endl;
		cout << "3.INORDER SUCCESSOR" << endl;
		cout << "4.INORDER" << endl;
		cout << "Enter Choice ->";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter an item -> ";
			cin >> key;
			t.insert(key);
			break;

		case 2:
			cout << "Enter a item to search : ";
			cin >> key;
			t.search(key);
			break;

		case 3:
			cout << (t.inorderSucc(t.root))->data << endl;
			break;

		case 4:
			t.inOrder();
			break;

		default:
			cout << "Invalid choice" << endl;
			exit(0);
		}
	}
}
