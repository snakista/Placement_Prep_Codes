#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prv;
};
struct node head;
struct node tail;
struct node* list_search(int x)
{
	struct node* tmp=head.next;
	while(tmp!=&tail&&tmp->data!=x)
	{
		tmp=tmp->next;
	}
	return tmp;
}
void insert(struct node* n,int x)
{
	struct node* tmp=new node();
	struct node* p=n->next;
	while(p!=&tail&&p->data<x)
	{
		p=p->next;
		if(p==&tail)
		break;
	}
	tmp->data=x;
	tmp->next=p;
	tmp->prv=p->prv;
	p->prv->next=tmp;
	p->prv=tmp;
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
void del(int x)
{
	if(head.next==&tail)
	{
		cout<<"List is already empty!"<<endl;
	}
	else
	{
		struct node* tmp=list_search(x);
		if(tmp==&tail)
		{
			cout<<"Element not found!"<<endl;
			return;
		}
		tmp->prv->next=tmp->next;
		tmp->next->prv=tmp->prv;
		delete(tmp);
	}
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
	cout<<"Enter values for sorted circular doubly linked list: ";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		insert(&head,item);
	}
	cout<<"Sorted Circular doubly linked list after insertion is: ";
	display();
	cout<<"Enter an element to delete from list: ";
	cin>>val;
	del(val);
	cout<<"List after deletion is: ";
	display();
}
