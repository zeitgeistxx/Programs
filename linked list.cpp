#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node(int val){
		data=val;
		next=NULL;
	}
};
void insertattail(node *&head,int value){
	node*newnode=new node(value);
	if(head==NULL){
		
		head=newnode;
	}
	node* curr=head;
	
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=newnode;
	newnode->next=NULL;
}
void display(node *head){
	node *curr=head;
	while(curr!=NULL){
		cout<<curr->data<<"->";
		curr=curr->next;
	}
	cout<<"NULL";
	cout<<endl;
}
void deleteatposition(node *&head,int pos){
	int count=1;
	node *curr=head;
	node *prev=NULL;
	if(pos==1){
		head=head->next;
	}
	while(count<=pos-1 && curr!=NULL){
		prev=curr;
		curr=curr->next;
		count++;
	}
	
	prev->next=curr->next;
	curr->next=NULL;
	
}
void evenafterodd(node * &head){ //1->2->3->4->5->6->null
	node*odd=head;
	node*even=head->next;
	node* evenstart=even;
	while(odd->next!=NULL && even->next!=NULL){
		odd->next=even->next;
		odd=odd->next;
		even->next=odd->next;
		even=even->next;
		
	}
	odd->next=evenstart;
	if(odd->next==NULL){//1->2->3->4->5->6->7->null
		even->next=NULL;
	}
}
void reversek(node*s,node*t){
	node* curr=s;
	node* next=s->next;
	node* prev=NULL;
	while(prev!=t ){
		
		curr->next=prev;
		prev=curr;
		curr=next;
		
		if(next!=NULL)next=next->next;
	}

	
}
node * reversegroupk(node *head,int k){
	if(head==NULL ||head->next==NULL||k==1)return head;
	node* tail=head;
	node*start=head;
	int inc=k-1;
	while(inc--){
		tail=tail->next;
		if(tail==NULL){
			return head;
		}
	}
	node *nexthead=reversegroupk(tail->next,k);
	reversek(start,tail);
	start->next=nexthead;
	return tail;
	
}
node * even1(node *&head){
	int i=0,j=0;
	int l1[100];
	int l2[100];
	node *temp=head;
	while(temp!=NULL){
		if(temp->data%2==0){
			l1[i++]=temp->data;
		}else{
			l2[j++]=temp->data;
		}
		temp=temp->next;
	}
	int l=0,m=0;
	while(temp!=NULL){
		if(l<i){
			temp->data=l1[l++];
		}else{
			temp->data=l2[m++];
		}
		temp=temp->next;
	}
	return head;
}
node * remove_dup_unsorted(node *&head){
	node *curr=head;
	node*prev=NULL;
	unordered_set<int>s;
	while(curr!=NULL){
		if(s.find(curr->data)==s.end()){
			s.insert(curr->data);
			prev=curr;
			curr=curr->next;
			
		}else{
			prev->next=curr->next;
			curr=curr->next;
		}
	}
	return head;
}
node *reverse(node * &head){
	int count=0;
	node* curr=head;
	node* next=NULL;
	node* prev=NULL;
	while(curr!=NULL ){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	cout<<"the no of nodes are ...:"<<count<<endl;
	return prev;
}
node * del_node_greateronright(node*&head){
	head=reverse(head);
	node *curr=head;
	node*curnext=curr->next;
	while(curnext!=NULL){
		if(curr->data>curnext->data){
			curr->next=curnext->next;
			curnext=curr->next;
		}else{
			curr=curnext;
			curnext=curnext->next;
		}
	}
	node *curr1=reverse(head);
	return curr1;
}
void insertdata(node* &head,int data1,int data2){
	node *newnode=new node(data2);
	node *temp=head;
	while(temp->data!=data1 &&temp!=NULL){
		temp=temp->next;
	}
	
	node* nextnode=temp->next;
	temp->next=newnode;
	newnode->next=nextnode;
	
	
}
int main(){
	node*head=NULL;
	insertattail(head,12);
	insertattail(head,15);
	insertattail(head,10);
	insertattail(head,11);
	insertattail(head,5);
	insertattail(head,6);
	display(head);
	deleteatposition(head,3);
	//insertattail(head,7);
	//node *newnode=reverse(head);
	//insertdata(head,5,7);
	display(head);
	
	//evenafterodd(head);
	//display(head);
	//node *newhead=reversegroupk(head,2);
	//display(newhead);
	
	//display(newhead);
	return 0;
}