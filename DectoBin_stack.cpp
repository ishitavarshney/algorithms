#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
}*top=NULL;

void push(int key)
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

/*void pop()
{
	cout<<"\npopping"<<top->data;
	node *ptr=top;
	top=top->next;
	delete ptr;
}*/

void show()
{
	node *ptr=top;
	cout<<"\nthe binary equivalent is:\n";
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
}

int main()
{
	int a;
	cout<<"\nenter no.";
	cin>>a;
	while(a)
	{
		push(a%2);
		a=a/2;
	}
	show();
	
}

