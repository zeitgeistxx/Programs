#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	Node *left;
	int data;
	Node *right;
	int height;
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
	int height(Node *);
	int getBalance(Node *);
	Node *leftRotate(Node *);
	Node *rightRotate(Node *);
	void insert(int);
	void search(int);
	void inorder(Node *);
	void preorder(Node *);
	void postorder(Node *);
};

int Tree::empty(){
	if (root == NULL)
		return 1;
	return 0;
}

Node *createNode(int key)
{
	Node *ptr = new Node;
	ptr->left = NULL;
	ptr->data = key;
	ptr->right = NULL;
	ptr->height = 1;
	return ptr;
}

int Tree::height(Node *r)
{
	if (r == NULL)
		return 0;
	return max(height(r->left), height(r->right)) + 1;
}

int Tree::getBalance(Node *r)
{
	return height(r->left) - height(r->right);
}

Node* Tree::leftRotate(Node *x)
{
	Node *y = x->right;
	Node *temp = y->left;
	y->left = x;
	x->right = temp;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

Node* Tree::rightRotate(Node *x)
{
	Node *y = x->left;
	Node *temp = y->right;
	y->right = x;
	x->left = temp;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}


void Tree::insert(int key){
	Node *curr = createNode(key);
    if (empty())
    {
		root = curr;
		return;
    }
    Node *temp = root, *parent;
    while (temp != NULL)
    {
        parent = temp;
        key < temp->data ? temp = temp->left : temp = temp->right;
    }
    key > parent->data ? parent->right = curr : parent->left = curr;

	int balance = getBalance(root);

	// Make the rotations
	if (balance > 1 && key < root->left->data) 
	{
		root = rightRotate(root);
	}
	if(balance < -1 && key > root->right->data) 
	{
		root = leftRotate(root);
	}
	if (balance > 1 && key > root->left->data) 
	{
		root->left = leftRotate(root->left);
		root = rightRotate(root);
	}
	if (balance < -1 && key < root->right->data) 
	{
		root->right = rightRotate(root->right);
		root = leftRotate(root);
	}
	root->height = max(height(root->left), height(root->right)) + 1;
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

void Tree::inorder(Node *r)
{
	if(empty()){
		cout << "Tree is Empty" << endl;
		return;
	}
	if (r == NULL)
		return;
	inorder(r->left);
	cout << r->data << " ";
	inorder(r->right);
}

void Tree::preorder(Node *r)
{
	if(empty()){
		cout << "Tree is Empty" << endl;
		return;
	}
	if (r == NULL)
		return;
	cout << r->data << " ";
	preorder(r->left);
	preorder(r->right);
}

void Tree::postorder(Node *r)
{
	if(empty()){
		cout << "Tree is Empty" << endl;
		return;
	}
	if (r == NULL)
		return;
	postorder(r->left);
	postorder(r->right);
	cout << r->data << " ";
}


int main()
{
	int data, choice;
	Tree t;
	while (true)
	{
		cout << "\n\n";
		cout << "1.INSERT" << endl;
		cout << "2.INORDER" << endl;
		cout << "3.PREORDER" << endl;
		cout << "4.POSTORDER" << endl;
		cout << "5.SEARCH" << endl;
		cout << "6.HEIGHT" << endl;
		cout << "Enter Choice -> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter a value -> ";
			cin >> data;
			t.insert(data);
			break;

		case 2:
			t.inorder(t.root);
			break;

		case 3:
			t.preorder(t.root);
			break;

		case 4:
			t.postorder(t.root);
			break;

		case 5:
			cout << "Enter a item to search : ";
			cin >> data;
			t.search(data);
			break;

		case 6:
			if(t.empty()){
				cout << "Height = 0" << endl;
			}
			else
				cout << "Height = " << t.root->height;
			break;

		default:
			cout << "Invalid Choice" << endl;
			exit(0);
		}
	}
}
