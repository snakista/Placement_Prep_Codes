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
	struct node* p=last->next;
	if(p==last)
	{
		if(p->data<key)
		{
			temp->data=key;
			p->next=temp;
			temp->next=p;
			last=temp;
		}
		else
		{
			temp->data=key;
			last->next=temp;
			temp->next=p;
		}
		return;
	}
	if(p->data>=key)
	{
		temp->next=p;
		temp->data=key;
		last->next=temp;
		return;
	}
	int f=0;
	while((p!=last->next||f==0)&&(p->next->data<key))
	{
		if(p==last)
		{
			temp->next=last->next;
			last->next=temp;
			temp->data=key;
			last=temp;
			return;
		}
		f=1;
		p=p->next;
	}
	temp->data=key;
	temp->next=p->next;
	p->next=temp;
}
int search(int key)
{
	struct node* ptr=last->next;
	int pos=1;
	do{
		if(ptr->data==key)
		{
			return pos;
		}
		pos++;
		ptr=ptr->next;
	}while(ptr!=last->next);
	return -1;
}
void del(int key)
{
	struct node* p;
	struct node* prv;
	p=last->next;
	if(p->data==key)
	{
		last->next=p->next;
		delete(p);
		return;
	}
	prv=p;
	p=p->next;
	while(p!=last->next&&p->data!=key)
	{
		prv=p;
		p=p->next;
	}
	prv->next=p->next;
	delete(p);
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
	int r=0,item,val;
	cout<<"Enter elements for circular singly linked list: ";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		if(r==0)
		{
			r=1;
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
	cout<<"Enter value to search: ";
	cin>>val;
	int res=search(val);
	if(res==-1)
	cout<<"Element not found!"<<endl;
	else
	cout<<"Element found at position: "<<res<<endl;
	cout<<"Enter value to delete from list: ";
	cin>>val;
	del(val);
	cout<<"Element after deletion are: ";
	display();
}
