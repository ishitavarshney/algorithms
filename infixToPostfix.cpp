#include<iostream>
#include<string.h>
using namespace std;
struct node{
	char data;
	node* next;
}*top=NULL;

void push(char key)
{
	node *np=new node;
	if(np==NULL)
	{
		cout<<"\nunable to create node";
		return;
	}
	//cout<<"\npushing"<<key;
	np->data=key;
	np->next=NULL;
	if(top==NULL)
		top=np;
	else
	{
		np->next=top;
		top=np;
	}
}

char pop()
{
	//cout<<"\npopping"<<top->data;
	
	node *ptr=top;
	top=top->next;
	char c=ptr->data;
	delete ptr;
	return c;
}

void show()
{
	node *ptr=top;
	cout<<"\nthe stack now is:\n";
	while(ptr!=NULL)
	{
		cout<<"\t"<<ptr->data;
		ptr=ptr->next;
	}
}

int precedence(char a)
{
	int b;
	switch (a)
	{
		case '-': b=1;	break;
		case '+':b=1;	 break;
		case '*':b=2;	break;
		case '/':b=2;	break;
		case '^':b=3;	break;
		case '(':b=0;	break;
	}
	return b;
}

int main()
{
	char exp[50];
	gets(exp);
	push('(');
	int l=strlen(exp);
	exp[l]=')';
	l=strlen(exp);
	for(int i=0;i<l;++i)
	{
		char c;
		int b;
		if((exp[i]>='A' && exp[i]<='Z') || (exp[i]>='a' && exp[i]<='z')||(exp[i]>='0'&&exp[i]<='9'))
			cout<<exp[i];
		else if(exp[i]=='(')
			push(exp[i]);
		else if(exp[i]==')')
		{
			while(top->data!='(')
			{
				c=pop();
				cout<<c;
			}
			pop();
		}
		else
		{
			b=precedence(exp[i]);
			if(top->data=='(' || b>precedence(top->data))
				push(exp[i]);
			else
			{
				while(b<=precedence(top->data))
				{
					c=pop();
					if(c!='(')
					cout<<c;
				}
				push(exp[i]);
			}
		}
		//show();
		
		
		
	}
	return 0;
	
	
}
