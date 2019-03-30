#include<iostream>
using namespace std;

struct node{
	int data;
	node *prev;
	node* next;
}*start=NULL,*rear=NULL;

void createnode(int key)
{
	cout<<"\ncreating node with value "<<key;
	node* np=new node;
	if(np==NULL)
	{
		cout<<"\nunable to create node";
		return;
	}
	if(start==NULL && rear==NULL)//list is empty
	{
		np->data=key;
		np->next=NULL;
		np->prev=NULL;
		start=rear=np;
		np=NULL;
	}
	else
	{
		np->data=key;
		np->next=start;
		np->prev=NULL;
		start->prev=np;
		start=np;
	} 
	
}

void insertmid(int key,int pos)
{
	cout<<"\ninserting node "<<key<<" after node "<<pos;
	if(start==NULL && rear==NULL)
		createnode(key);
	else
	{
		node *ptr=start;
		while(ptr!=NULL)
		{
			if(ptr->data==pos)
				break;
			ptr=ptr->next;
		}
		node *np=new node;
		if(np==NULL)
		{
			cout<<"\nunable to create node!";
			return;
		}
		np->data=key;
		np->next=ptr->next;
		np->prev=ptr;
		ptr->next=np;
		ptr=np->next;
		ptr->prev=np;
	}
}

void insertend(int key)
{
	cout<<"\ninserting node "<<key<<" at the end ";
	node *np=new node;
	if(np==NULL)
	{
		cout<<"\nunable to create node!";
		return;
	}
	np->data=key;
	np->next=NULL;
	np->prev=rear;
	rear->next=np;
	rear=np;
}

void delnode(int key)
{
	cout<<"\ndeleting node "<<key;
	if(start->data==key)
	{
		node *ptr=start;
		start=start->next;
		start->prev=NULL;
		delete ptr;
		return;
	}
	if(rear->data==key)
	{
		node *ptr=rear;
		rear=rear->prev;
		rear->next=NULL;
		delete ptr;
		return;
	}
	node *ptr=start->next;
	bool flag=0;
	while(ptr->next!=NULL)
	{
		if(ptr->data==key)
		{
			flag=1;
			break;
		}
		ptr=ptr->next;
	}
	if(flag==0)
	{
		cout<<"\nelement not found!";
		return;
	}
	node *n=ptr->next;
	node *p=ptr->prev;
	p->next=n;
	n->prev=p;
	delete ptr;
}

void showfront()
{
	cout<<"\ntraversing list from front\n";
	if(start==NULL)
		cout<<"\nlist is empty!";
	else
	{
		node *ptr=start;
		cout<<endl;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->next;
		}
	}
}

void showrev()
{
	cout<<"\ntraversing list backwards\n";
	if(rear==NULL)
		cout<<"\nempty list!";
	else
	{
		node *ptr=rear;
		cout<<endl;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->prev;
		}
	}
}

int main()
{
	for(int i=35;i>=5;i-=5)
		createnode(i);
	showfront();
	showrev();
	insertmid(28,25);
	showfront();
	showrev();
	insertend(40);
	showfront();
	showrev();
	delnode(5);
	showfront();
	showrev();
	delnode(25);
	showfront();
	showrev();
	return 0;
}
