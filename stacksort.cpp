#include<iostream>
using namespace std;
struct node{
	int data;
	node *link;
};

void push(int key,node **top)
{
	node *np=new node;
	if(np==NULL)
	 return;
	np->data=key;
	np->link=NULL;
	if(*top==NULL)
		*top=np;
	else
	{
	
		np->link=*top;
		*top=np;
	}
}

int pop(node **top)
{
	int temp=(*top)->data;
	node *t=*top;
	*top=(*top)->link;
	delete t;
	return temp;
}

void display(node **top)
{
	node *ptr=*top;
	while(ptr!=NULL)
	{
		cout<<"  "<<ptr->data;
		ptr=ptr->link;
	}
}

int main()
{
	node *stack1=NULL,*stack2=NULL;
	int n,key;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>key;
		push(key,&stack1);
	}
	while(stack1!=NULL)
	{
		int temp=pop(&stack1);
		while(stack2!=NULL && stack2->data<temp)
		{
			push(pop(&stack2),&stack1);
		}
		push(temp,&stack2);
	}
	cout<<"\nsorted stack is:";
	display(&stack2);
	return 0;
}







