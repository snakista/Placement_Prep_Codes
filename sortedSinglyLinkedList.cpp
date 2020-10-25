#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node* head=NULL;
void sortedInsert(int key)
{
	struct node* tmp=new node();
	if(head==NULL||head->data>=key)
	{
		tmp->data=key;
		tmp->next=head;
		head=tmp;
	}
	else
	{
		struct node* p=head;
		while(p->next!=NULL&&(p->next->data<key))
		{
			p=p->next;
    	}
    	tmp->next=p->next;
    	tmp->data=key;
    	p->next=tmp;
	}
}
int search(int key)
{
	struct node* it=head;
	int pos=1;
	while(it!=NULL)
	{
		if(it->data==key)
		{
			return pos;
		}
		pos++;
		it=it->next;
	}
	return -1;
}
void del_node(int key)
{
	struct node* ptr;
	struct node* prv;
	ptr=head;
	if(ptr!=NULL&&ptr->data==key)
	{
		head=ptr->next;
		delete(ptr);
		return;
	}
	while(ptr!=NULL&&ptr->data!=key)
	{
		prv=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		cout<<"Element not present!"<<endl;
	}
	prv->next=ptr->next;
	delete(ptr);
}
void display()
{
	struct node* ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
int main()
{
	cout<<"Enter no of values:";
	int n,t,k,d;
	cin>>n;
	cout<<"Enter the values to insert in sorted singly linked list:";
	for(int i=0;i<n;i++)
	{
		cin>>t;
		sortedInsert(t);
	}
	cout<<"List after insertion is: ";
	display();
	cout<<endl;
	cout<<"Enter value to search in linked list:"<<endl;
	cin>>k;
	int res=search(k);
	if(res==-1)
	cout<<"Element not found!";
	else
	cout<<"Element found at position "<<res<<endl;
	cout<<endl;
	cout<<"Enter a value to delete from linked list:";
	cin>>d;
	del_node(d);
	cout<<"List after deletion is: ";
	display();
}
