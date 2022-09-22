#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    int isEmpty();
    void insert(int);
    void inOrder(Node *);
    void preOrder(Node *);
    void postOrder(Node *);
    void search(int);
    void smallest();
    void largest();
    int totalNodes(Node *);
    void del(int);
};

int Tree::isEmpty()
{
    if (root == NULL)
        return 1;
    return 0;
}

Node *createNode(int item)
{
    Node *ptr = new Node;
    ptr->lchild = NULL;
    ptr->data = item;
    ptr->rchild = NULL;
    return ptr;
}

void Tree::insert(int key)
{
    Node *curr = createNode(key);
    if (isEmpty())
    {
        root = curr;
        return;
    }
    Node *temp = root, *parent;
    while (temp != NULL)
    {
        parent = temp;
        if (key < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    if (key > parent->data)
        parent->rchild = curr;
    else
        parent->lchild = curr;
}

void Tree::inOrder(Node *r)
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (r == NULL)
        return;
    inOrder(r->lchild);
    cout << r->data << " ";
    inOrder(r->rchild);
}

void Tree::preOrder(Node *r)
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (r == NULL)
        return;
    cout << r->data << " ";
    preOrder(r->lchild);
    preOrder(r->rchild);
}

void Tree::postOrder(Node *r)
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (r == NULL)
        return;
    postOrder(r->lchild);
    postOrder(r->rchild);
    cout << r->data << " ";
}

void Tree::search(int key)
{
    if (isEmpty())
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
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    cout << "Item not Found" << endl;
}

void Tree::smallest()
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    Node *temp = root;
    while (temp->lchild != NULL)
        temp = temp->lchild;
    cout << "Smallest Element -> " << temp->data;
}

void Tree::largest()
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    Node *temp = root;
    while (temp->rchild != NULL)
        temp = temp->rchild;
    cout << "Largest Element -> " << temp->data;
}

int Tree::totalNodes(Node *r)
{
    if (r == NULL)
        return 0;
    else
        return totalNodes(r->lchild) + totalNodes(r->rchild) + 1;
}

void Tree::del(int key)
{
    Node *temp = root, *parent = NULL;
    while (temp != NULL && key != temp->data)
    {
        parent = temp;
        if (key < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    if (temp == NULL)
    {
        cout << "Item not found" << endl;
        return;
    }
    if (temp->lchild == NULL || temp->rchild == NULL)
    {
        Node *ptr;
        if (temp->lchild == NULL)
            ptr = temp->rchild;
        else
            ptr = temp->lchild;

        if (parent == NULL)
        {
            root = ptr;
            return;
        }
        if (parent->lchild == temp)
            parent->lchild = ptr;
        else
            parent->rchild = ptr;

        delete temp;
        temp = NULL;
    }

    // When both of the children node is present
    else
    {
        Node *succ = temp->rchild, *psucc = NULL;
        while (succ->lchild != NULL)
        {
            psucc = succ;
            succ = succ->lchild;
        }
        temp->data = succ->data;
        if (psucc == NULL)
            temp->rchild = succ->rchild;
        else
            psucc->lchild = succ->rchild;

        delete succ;
        succ = NULL;
    }
}

int main()
{
    Tree t;
    int item, choice;
    while (true)
    {
        cout << "\n\n";
        cout << "1.INSERT" << endl;
        cout << "2.INORDER" << endl;
        cout << "3.PREORDER" << endl;
        cout << "4.POSTORDER" << endl;
        cout << "5.SEARCH" << endl;
        cout << "6.SMALLEST ELEMENT" << endl;
        cout << "7.LARGEST ELEMENT" << endl;
        cout << "8.TOTAL NODES" << endl;
        cout << "9.DELETE" << endl;
        cout << "Enter Choice ->";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a item :";
            cin >> item;
            t.insert(item);
            break;

        case 2:
            t.inOrder(t.root);
            break;

        case 3:
            t.preOrder(t.root);
            break;

        case 4:
            t.postOrder(t.root);
            break;

        case 5:
            cout << "Enter a item to search in BST :";
            cin >> item;
            t.search(item);
            break;

        case 6:
            t.smallest();
            break;

        case 7:
            t.largest();
            break;

        case 8:
            cout << "Total Nodes in BST ->" << t.totalNodes(t.root);
            break;

        case 9:
            if (!t.isEmpty())
            {
                cout << "Enter an item to delete :";
                cin >> item;
                t.del(item);
            }
            else
            {
                cout << "Tree is empty" << endl;
            }
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}