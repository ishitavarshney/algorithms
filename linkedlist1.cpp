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
		//cin>>np->data;
		np->data=key;
		np->link=start;
		start=np;
		np=NULL;
		
	}
	//delete np;
	
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
		while(ptr)
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
		}
		if(ptr==NULL && flag==0)
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
		
		
		start=ptr->link;
		flag=1;
		delete ptr;
		return;
	}
	node *prev=start;
	ptr=start->link;
	while(ptr)
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

void searchnode(int key)
{
	cout<<"\nsearching node with value"<<key;
	bool flag=0;
	int count=0;
	node *ptr=start;
	while(ptr)
	{
		++count;
		if(ptr->data==key)
		{
			cout<<"\nposition is"<<count;
			flag=1;
			break;
		}
		ptr=ptr->link;
	}
	if(ptr==NULL && flag==0)
		cout<<"\nunable to find node!";
	
}

void ctr(int key)
{
	cout<<"\ncounting occurences of "<<key;
	int count=0;
	node *ptr=start;
	while(ptr)
	{
		
		if(ptr->data==key)
		{
			++count;
		}
		ptr=ptr->link;
	}
	cout<<"\nthe count is:"<<count;
}

void showlist()
{
	if(start==NULL)
	{
		cout<<"\nempty list!";
		return;
	}
	node* ptr=start;
	cout<<"\n";
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->link;
	}
}

int main()
{
	for(int i=60;i>=10;i-=10)
	{
		createnode(i);
	}
	
	showlist();
	createnode(5);
	showlist();
	insertmid(35,30);
	showlist();
	delnode(50);
	showlist();
	delnode(5);
	showlist();
	delnode(60);
	showlist();
	delnode(50);
	showlist();
	searchnode(35);
	createnode(35);
	insertmid(35,40);
	insertmid(35,20);
	insertmid(50,40);
	insertmid(35,50);
	showlist();
	ctr(35);
	
	return 0;
}

