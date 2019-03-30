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
void show()
{
	node *ptr=top;
	cout<<"\nthe reverse string is:\n";
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
}

int main()
{
	char s[50];
	cout<<"\nenter string to be reversed:";
	gets(s);
	for(int i=0;s[i]!='\0';++i)
	{
		if(s[i]==' ')
			continue;
		push(s[i]);
			
	}
	show();
	return 0;
}
