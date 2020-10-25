#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node* head=NULL;
void insert(int data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=head;
	head=new_node;
}
void display(){
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
int main()
{
	insert(5);
	insert(3);
	insert(2);
	insert(5);
	insert(4);
	insert(7);
	insert(4);
	insert(2);
	cout<<"The linked list is:";
	display();
}
