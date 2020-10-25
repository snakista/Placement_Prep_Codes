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
