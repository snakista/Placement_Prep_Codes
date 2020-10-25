#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node* next;
};
node* head=NULL;
void push(int key)
{
	struct node* new_node=new node();
	new_node->val=key;
	new_node->next=head;
	head=new_node;
}
int search(int key)
{
	struct node* it=head;
	int pos=1;
	while(it!=NULL)
	{
		if(it->val==key)
		{
			return pos;
		}
		pos++;
		it=it->next;
	}
	return -1;
}
void display()
{
	struct node* ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->val<<" ";
		ptr=ptr->next;
	}
}
void del_node(int key)
{
	struct node* ptr;
	struct node* prv;
	ptr=head;
	if(ptr!=NULL&&ptr->val==key)
	{
		head=ptr->next;
		delete(ptr);
		return;
	}
	while(ptr!=NULL&&ptr->val!=key)
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
int main()
{
	cout<<"Enter no of values:";
	int n,t,k,d;
	cin>>n;
	cout<<"Enter the values to insert in singly linked list:";
	for(int i=0;i<n;i++)
	{
		cin>>t;
		push(t);
	}
	cout<<"Enter value to search in linked list:"<<endl;
	cin>>k;
	int res=search(k);
	if(res==-1)
	cout<<"Element not found!";
	else
	cout<<"Element found at position "<<res<<endl;
	cout<<"Enter a value to delete from linked list:";
	cin>>d;
	del_node(d);
	cout<<"List after deletion is: ";
	display();
}
