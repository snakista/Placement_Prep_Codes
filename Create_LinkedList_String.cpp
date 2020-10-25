#include<bits/stdc++.h>
using namespace std;
struct node{
	char data[10];
	struct node *next;
};
struct node* head=NULL;
void insert(char *str)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	strcpy(new_node->data,str);
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
	insert("India");
	insert("Russia");
	insert("Canada");
	insert("China");
	insert("United states");
	insert("Brazil");
    insert("Australia");
	cout<<"The linked list is: ";
	display();
}
