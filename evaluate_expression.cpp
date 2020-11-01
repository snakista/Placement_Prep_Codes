#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct nodec{
	char data;
	struct nodec* next;
};
struct nodei{
	int data;
	struct nodei* next;
};
struct nodec* top_c=NULL;
struct nodei* top_i=NULL;
bool is_empty_c()
{
	if(top_c==NULL)
	return true;
	else
	return false;
}
bool is_empty_i()
{
	if(top_i==NULL)
	return true;
	else
	return false;
}
void pushc(char x)
{
	struct nodec* tmp=new nodec();
	tmp->data=x;
	tmp->next=top_c;
	top_c=tmp;
}
void pushi(int x)
{
	struct nodei* tmp=new nodei();
	tmp->data=x;
	tmp->next=top_i;
	top_i=tmp;
}
void popc()
{
	if(top_c==NULL)
	{
		cout<<"Stack is empty!"<<endl;
		return;
	}
	else
	{
		struct nodec* tmp=top_c;
		//cout<<tmp->data<<" ";
		top_c=top_c->next;
		delete(tmp);
	}
}
int popi()
{
	if(top_i==NULL)
	{
		cout<<"Stack is empty!"<<endl;
		return -1;
	}
	else
	{
		struct nodei* tmp=top_i;
		int val=tmp->data;
		top_i=top_i->next;
		delete(tmp);
		return val;
	}
}
int prec(char c)
{
	if(c=='^')
	return 3;
	else if(c=='*'||c=='/')
	return 2;
	else if(c=='+'||c=='-')
	return 1;
	else
	return 0;
}
string infixToPostfix(string s)
{
	pushc('N');
	int l=s.length();
	string ns;
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			string k;
			int j=i;
			while(s[j]>='0'&&s[j]<='9')
			{
				k+=s[j];
				j++;
			}
			ns+=k;
			ns+=' ';
			j--;
			i=j;
		}
		else if(s[i]=='(')
		pushc('(');
		else if(s[i]==')')
		{
			while(top_c->data!='N'&&top_c->data!='(')
			{
				char c=top_c->data;
				popc();
				ns+=c;
			}
			if(top_c->data=='(')
			{
				char c=top_c->data;
				popc();
			}
		}
		else
		{
			while(top_c->data!='N'&&(prec(s[i])<=prec(top_c->data)))
			{
				char c=top_c->data;
				popc();
				ns+=c;
			}
			pushc(s[i]);
		}
	}
	while(top_c->data!='N')
	{
		char c=top_c->data;
		popc();
		ns+=c;
	}
	return ns;
}
void evaluate(string s)
{
	int i;
	for(i=0;i<s.length();i++)
	{
		if(s[i]==' ')
		continue;
		else if(isdigit(s[i]))
		{
			int num=0;
			while(isdigit(s[i]))
			{
				num=num*10+(int)(s[i]-'0');
				i++;
			}
			i--;
			pushi(num);
		}
		else
		{
			int val1=popi();
			int val2=popi();
			switch(s[i])
			{
				case '+': pushi(val1+val2);
				          break;
				case '-': pushi(val2-val1);
				          break;
				case '*': pushi(val2*val1);
				          break;
				case '/': pushi(val2/val1);
				          break;
			}
		}
	}
	int ans=popi();
	cout<<ans;
}
int main()
{
	string exp;
	cout<<"Enter an expression: ";
	cin>>exp;
	string s=infixToPostfix(exp);
	evaluate(s);
	
}
