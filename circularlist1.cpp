#include<iostream>
using namespace std;
struct node{
	int data;
	node* link;
}*start=NULL;

void createnode(int key)
{
	cout<<"\ncreating node of value "<<key;
	node *np=new node;

	if(np==NULL)
	{
		cout<<"\nünable to create node!";
		
	}
	else
	{

		
		if(start==NULL)
		{
			start=np;
			np->data=key;
			np->link=np;
		}
		np->data=key;
		np->link=start;
		node *ptr=start;
		while(ptr->link!=start)
			ptr=ptr->link;
		ptr->link=np;
		start=np;
		
		
	}
	
	
}
void insertmid(int key,int pos)
{
	cout<<"\ninserting node with value "<<key<<" after node "<<pos;
	if(start==NULL)
	{
		createnode(key);
		return;
	}
	node* np=new node;
	if(np==NULL)
		cout<<"\nunable to create node";
	else
	{
	
		node* ptr=start;
		bool flag=0;
		do
		{
			if(ptr->data==pos)
			{
				
				np->data=key;
				np->link=ptr->link;
				ptr->link=np;
				flag=1;
				break;
				
			}
			ptr=ptr->link;
		}while(ptr!=start);
		if(ptr==start && flag==0)
		{
			cout<<"\nunable to find desired position for insertion in list";
		}
	}
}

void delnode(int key)
{
	cout<<"\ndeleteing node with value"<<key;
	bool flag=0;
	node *ptr=start;
	if(start->data==key)
	{
		
		while(ptr->link!=start)
			ptr=ptr->link;
		ptr->link=start->link;
		node *n=start;
		start=start->link;
		
		flag=1;
		delete n;
		return;
		
	}
	
	
	node *prev=start;
	ptr=start->link;
	while(ptr!=start)
	{
		if(ptr->data==key)
		{
			
			prev->link=ptr->link;
			delete ptr;
			flag=1;
			break;
			
			
		}
		
		prev=ptr;
		ptr=ptr->link;
		
	}
	if(flag==0)
	{
		cout<<"\nunable to find element";
	}
}



void showlist()
{
	if(start==NULL)
	{
		cout<<"\nempty list!";
		return;
	}
	node* ptr=start->link;
	cout<<"\n";
	cout<<start->data<<"\t";
	while(ptr!=start)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->link;
		if(ptr==start)
			cout<<ptr->data;
	}
}

int main()
{
	for(int i=50;i>=10;i-=10)
	{
		createnode(i);
		//showlist();
	}
	
	showlist();
	createnode(5);
	showlist();
	insertmid(35,30);
	showlist();
	insertmid(60,50);
	showlist();
	delnode(30);
	showlist();
	delnode(5);
	showlist();
	delnode(60);
	showlist();
	delnode(60);
	showlist();
	//searchnode(35);
	//createnode(35);
	//insertmid(35,40);
	//insertmid(35,20);
	//insertmid(50,40);
	//insertmid(35,50);
	//showlist();
	//ctr(35);
	
	return 0;
}

