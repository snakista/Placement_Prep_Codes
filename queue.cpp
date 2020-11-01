#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prv;
};
struct node head;
struct node tail;
void enqueue(int x)
{
	struct node* tmp=new node();
	struct node* n=&head;
	tmp->next=n->next;
	tmp->prv=n;
	n->next->prv=tmp;
	n->next=tmp;
	tmp->data=x;
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
void dequeue()
{
	if(head.next==&tail)
	{
		cout<<"List is already empty!"<<endl;
	}
	else
	{
		struct node* n=tail.prv;
		n->prv->next=n->next;
		n->next->prv=n->prv;
		delete(n);
	}
}
int main()
{
	head.next=&tail;
	head.prv=&tail;
	tail.next=&head;
	tail.prv=&head;
	int n,val;
	cout<<"Enter number of values to enqueue: ";
	cin>>n;
	cout<<"Enter values: ";
	for(int i=0;i<n;i++)
	{
		cin>>val;
		enqueue(val);
		cout<<"Elements after enqueue "<<i+1<<" is : ";
		display();
	}
	cout<<"Enter number of dequeues: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element after dequeue "<<i+1<<" is : ";
		dequeue();
		display();
		cout<<'\n';
	}
}
