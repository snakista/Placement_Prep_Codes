#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node* last=NULL;
void addFirst(int key)
{
	struct node* temp=new node();
	temp->data=key;
	last=temp;
	last->next=last;
}
void insert(int key)
{
	if(last==NULL)
	{
		addFirst(key);
	}
	struct node* temp=new node();
	temp->data=key;
	temp->next=last->next;
	last->next=temp;
}
void rev()
{
	if(last==NULL)
	{
		cout<<"List is empty!"<<endl;
		return;
	}
	struct node* prv=last;
	struct node* cur=last->next;
	struct node* next=cur;
	do{
		if(cur==last)
		break;
		next=cur->next;
		cur->next=prv;
		prv=cur;
		cur=next;
	}while(prv!=last);
	cur->next=prv;
	struct node* p=last;
	do{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=last);
}
void display()
{
	struct node* p;
	if(last==NULL)
	{
		cout<<"List is empty!"<<endl;
		return;
	}
	p=last->next;
	do{
		cout<<p->data<<" ";
		p=p->next;
	}
	while(p!=last->next);
}
int main()
{
	cout<<"Enter no of values to enter: ";
	int n;
	cin>>n;
	int f=0,item,val;
	cout<<"Enter elements for circular singly linked list: ";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		if(f==0)
		{
			f=1;
			addFirst(item);
		}
		else
		{
			insert(item);
		}
	}
	cout<<"Elements of circular singly linked list are: ";
	display();
	cout<<endl;
	cout<<"Elements after reversal is: ";
	rev();
}
