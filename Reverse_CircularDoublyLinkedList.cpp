#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prv;
};
struct node head;
struct node tail;
void insert(struct node* n,int x)
{
	struct node* tmp=new node();
	tmp->next=n->next;
	tmp->prv=n;
	n->next->prv=tmp;
	n->next=tmp;
	tmp->data=x;
}
void rev()
{
	struct node* p=head.next;
	struct node* t;
	while(p!=&tail)
	{
		t=p->next;
		p->next=p->prv;
		p->prv=t;
		p=p->prv;
	}
	t=head.next;
	head.next->next=&tail;
	tail.prv->prv=&head;
	head.next=tail.prv;
	head.prv=&tail;
	tail.next=&head;
}
void display()
{
	struct node* p=head.next;
	while(p!=&tail)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	head.next=&tail;
	head.prv=&tail;
	tail.next=&head;
	tail.prv=&head;
	cout<<"Enter no of values: ";
	int n,item,val;
	cin>>n;
	cout<<"Enter values: ";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		insert(&head,item);
	}
	cout<<"Circular doubly linked list after insertion is: ";
	display();
	cout<<"Circular Linked List after reversal is: ";
	rev();
	display();
}
