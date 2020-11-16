#include<iostream>
using namespace std;
struct node{
	int key;
	struct node* p;
	struct node *left,*right;
};
struct node* root=NULL;
void insert(int val)
{
	struct node *y=NULL;
	struct node *r=root;
	struct node *x=new node();
	x->key=val;
	while(r!=NULL)
	{
		y=r;
		if(x->key<r->key)
     	r=r->left;
		else
		r=r->right;
	}
	x->p=y;
	if(y==NULL)
	root=x;
	else if(x->key<y->key)
	{
		y->left=x;
	}
	else
	{
		y->right=x;
	}
}
struct node* search(struct node* ptr,int x)
{
	if(ptr==NULL||ptr->key==x)
	{
		return ptr;
	}
	if(x<ptr->key)
	{
		return search(ptr->left,x);
	}
	else
	{
		return search(ptr->right,x);
	}
}
int main()
{
	int n,val;
	cout<<"Enter number of values to insert: ";
	cin>>n;
	cout<<"Enter values: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		insert(val);
	}
	cout<<"Enter a value to search in the tree: ";
	cin>>val;
	struct node* x=search(root,val);
	if(x==NULL)
	{
		cout<<"Element not found!"<<endl;
	}
	else
	{
		cout<<"Element "<<x->key<<" is present in tree!"<<endl;
	}
}
