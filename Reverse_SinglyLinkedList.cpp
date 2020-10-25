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
void rev()
{
	struct node* prv=NULL;
	struct node* cur=head;
	struct node* next=NULL;
	while(cur!=NULL)
	{
		next=cur->next;
		cur->next=prv;
		prv=cur;
		cur=next;
	}
	head=prv;
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
	cout<<"Singly linked list is: ";
	display();
	cout<<endl;
	cout<<"List after reversal is:";
	rev();
	display();
}
