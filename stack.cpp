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
	cout<<"\npushing"<<key;
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

void pop()
{
	cout<<"\npopping"<<top->data;
	node *ptr=top;
	top=top->next;
	delete ptr;
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

int main()
{
	int a;
	char ans='y';
	do{
		cout<<"\n1.push \n2.pop\n3.display\n";
		cin>>a;
		switch(a)
		{
			case 1: int keyl;
					cout<<"\nenter stack value";
					cin>>keyl;
					push(keyl);
					show();
					break;
			case 2: pop();
					show();
					break;
			case 3: show();
					break;
			default:cout<<"\ninvalid option!";
			
		}
		cout<<"\ndo you want to continue?(y/n)";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}
