#include<iostream>
#include<stdio.h>
using namespace std;
int top=-1;
int arr[101];
bool stack_empty()
{
	if(top==-1)
	{
		return true;
	}
	else
	return false;
}
void push(char x)
{
	if(top==100)
	{
		cout<<"Stack overflow!"<<endl;
	}
	else
	{
		top++;
		arr[top]=x;
	}
}
void pop()
{
	if(stack_empty())
	{
		cout<<"Stack underflow!"<<endl;
		return;
	}
	else
	{
		printf("%c",arr[top--]);
	}
}
int main()
{
	string str;
	cout<<"Enter a string: ";
	getline(cin,str);
	for(int i=0;i<str.size();i++)
	{
		push(str[i]);
	}
	while(!stack_empty())
	{
		pop();
	}
}
