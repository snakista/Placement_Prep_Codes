#include<bits/stdc++.h>
using namespace std;
struct stud{
	char name[30];
	int st_id;
	char sem[5];
	float cgpa;
};
struct node{
	stud data;
	struct node *next;
};
struct node* head=NULL;
void insert(stud data)
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
		cout<<"Name: "<<ptr->data.name<<endl; 
		cout<<"ID: "<<ptr->data.st_id<<endl;
		cout<<"Semester: "<<ptr->data.sem<<endl;
		cout<<"CGPA: "<<ptr->data.cgpa<<endl;
		ptr=ptr->next;
	}
}
int main()
{
	stud s[5];
	for(int i=0;i<3;i++)
	{
		cout<<"Enter name:";
		cin>>s[i].name;
		cout<<"Enter Id:";
		cin>>s[i].st_id;
		cout<<"Enter Semester:";
		cin>>s[i].sem;
		cout<<"Enter cgpa:";
		cin>>s[i].cgpa;
		insert(s[i]);
	}
	cout<<"The linked list is:";
	display();
}
