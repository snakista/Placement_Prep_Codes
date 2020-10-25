#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prv;
};
struct node* head=NULL;
void insert(int x)
{
	struct node* tmp=new node();
	tmp->next=head;
	tmp->data=x;
	if(head!=NULL)
	{
		head->prv=tmp;
	}
	tmp->prv=NULL;
	head=tmp;
}
void rev()
{
	struct node* temp=NULL;
	struct node* cur=head;
	while(cur!=NULL)
	{
	    temp=cur->prv;
	    cur->prv=cur->next;
	    cur->next=temp;
	    cur=cur->prv;
	}
	if(temp!=NULL)
	{
		head=temp->prv;
	}
}
void display()
{
	struct node* p=head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	int n,item,val;
	cout<<"Enter the number of values: ";
	cin>>n;
	cout<<"Enter the values for doubly linked list: ";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		insert(item);
	}
	cout<<"Elements in doubly linked list are: ";
	display();
	cout<<endl;
	cout<<"Elements after reversal is: ";
	rev();
	display();
	cout<<endl;
}
