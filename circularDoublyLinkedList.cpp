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
	cout<<"Enter values: ";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		insert(&head,item);
	}
	cout<<"Circular doubly linked list after insertion is: ";
	display();
	cout<<"Enter an element to delete from list: ";
	cin>>val;
	del(val);
	cout<<"List after deletion is: ";
	display();
}
