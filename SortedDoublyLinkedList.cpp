#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prv;
};
struct node* head=NULL;
int search(int x)
{
	struct node* tmp=head;
	int pos=1;
	while(tmp!=NULL)
	{
		if(tmp->data==x)
		{
			return pos;
		}
		pos++;
		tmp=tmp->next;
	}
	return -1;
}
void del(int x)
{
	if(head==NULL)
	{
		cout<<"List is empty!"<<endl;
		return;
	}
	struct node* p=head;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			if(p->prv!=NULL)
			{
				p->prv->next=p->next;
			}
			else
			{
				head=p->next;
			}
			if(p->next!=NULL)
			{
				p->next->prv=p->prv;	
			}
			delete(p);
			return;
		}
		p=p->next;
	}
}
void insert(int key)
{
	struct node* tmp=new node();
	struct node* p=head;
	if(head==NULL)
	{
		tmp->data=key;
		tmp->next=head;
		tmp->prv=NULL;
		head=tmp;
		return;
	}
	while(p->next!=NULL&&p->data<key)
	{
		p=p->next;
	}
	if(p->next==NULL)
	{
		if(p->data>=key)
		{
			if(p==head)
			{
				tmp->data=key;
				tmp->next=head;
				head->prv=tmp;
				tmp->prv=NULL;
				head=tmp;
			}
			else
			{
				tmp->data=key;
				tmp->next=p;
				p->prv->next=tmp;
				tmp->prv=p->prv;
				p->prv=tmp;
			}
		}
		else
		{
		tmp->data=key;
		p->next=tmp;
		tmp->prv=p;
		tmp->next=NULL;
	    }
	}
	else
	{
		if(p->prv==NULL)
		{
			tmp->data=key;
			tmp->next=p;
			tmp->prv=NULL;
			p->prv=tmp;
			head=tmp;
		}
		else{
		tmp->data=key;
		tmp->next=p;
		tmp->prv=p->prv;
		p->prv->next=tmp;
		p->prv=tmp;
	    }
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
	cout<<"Enter the values for sorted doubly linked list: ";
	for(int i=0;i<n;i++)
	{
		cin>>item;
		insert(item);
	}
	cout<<"Elements in sorted doubly linked list are: ";
	display();
	cout<<"Enter an element to search: ";
	cin>>val;
	int res=search(val);
	if(res==-1)
	cout<<"Element not found!"<<endl;
	else
	cout<<"Element found at position :"<<res<<endl;
	cout<<"Enter an element to delete from list: ";
	cin>>val;
	del(val);
	cout<<"List after deletion is: ";
	display();
}
