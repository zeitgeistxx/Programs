#include<iostream>
using namespace std;

struct Node{
	int coef;
	int exp;
	Node *next;
};

class Poly{
	Node *head;
	
public:
	Poly(){
		head=NULL;
	}
	void createPoly(int,int);
	void addPoly(Node *p1, Node *p2);
	void display();
};

void Poly::createPoly(int c, int e){
	Node *curr = new Node;
	curr->next=NULL;
	curr->coef=c;
	curr->exp=e;
	if(head==NULL){  // Empty List
		head=curr;
		return;
	}
	Node *temp=head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=curr;
}

void Poly::display(){
	Node *p = head;
	while(p->next!=NULL){
		cout<<p->coef<<"x^"<<p->exp;
		if(p->next->coef>=0) cout<<"+";
		p=p->next;
	}
	cout<<p->coef<<"x^"<<p->exp;
}



int main()
{
	Poly p1,p2;
	int c,e,choice;
	
	while(true){
		cout<<"Press 1 to create a polynomial"<<endl;
		cout<<"Press 2 to display the polynomial"<<endl;
		cout<<"Enter Choice ->";
		cin>>choice;
		
		switch(choice){
			case 1: cout<<"Enter coefficient and exponent ->";
					cin>>c>>e;
					p1.createPoly(c,e);
					break;
				
			case 2: p1.display();
					break;
		}
	}
	
		

}
