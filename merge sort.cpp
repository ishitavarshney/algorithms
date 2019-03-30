#include<iostream>
using namespace std;
void mergesort(int *a,int n);
void merge(int *a,int *l,int *r,int n);

void mergesort(int *a,int n)
{
	if(n<2)
	{
		return;
	}
	int n1=n/2;
	int n2=n-n1;
	int l[n1],r[n2];
	for(int i=0;i<n1;++i)
	{
		l[i]=a[i];
	}
	for(int i=n1;i<n;++i)
	{
		r[i-n/2]=a[i];
	}
	mergesort(l,n1);
	mergesort(r,n2);
	merge(a,l,r,n);
	
}
void merge(int *a,int *l,int *r,int n)
{
	int i=0,j=0,k=0,n1=n/2,n2=n-n/2;
	while(k<n && i<n1 && j<n2)
	{
		if(l[i]<=r[j])
		{
			a[k]=l[i];
			++i;
			++k;
		}
		else
		{
			a[k]=r[j];
			++j;
			++k;
		}
	}
	while(i<n1)
	{
		a[k]=l[i];
		++i;
		++k;
	}
	while(j<n2)
	{
		a[k]=r[j];
		++j;
		++k;
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;++i)
		cin>>a[i];
	
	mergesort(a,n);
	cout<<"\nsorted array:";
	for(int i=0;i<n;++i)
		cout<<"\t"<<a[i];
	return 0;
}
