#include<iostream>
using namespace std;
void quicksort(int *a,int beg,int end);
int partition(int *a,int beg,int end);
void quicksort(int *a,int beg,int end)
{
	if(beg>=end)
		return;
	int pindex=partition(a,beg,end);
	quicksort(a,0,pindex-1);
	quicksort(a,pindex+1,end);
	
}
int partition(int *a,int beg,int end)
{
	int pivot=a[end];
	int pindex=0;
	for(int i=beg;i<end;++i)
	{
		if(a[i]<pivot)
		{
			int t=a[pindex];
			a[pindex]=a[i];
			a[i]=t;
			++pindex;
		}
	}
	int t=a[pindex];
	a[pindex]=a[end];
	a[end]=t;
	return pindex;
}
int main()
{
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;++i)
		cin>>a[i];
	
	quicksort(a,0,n-1);
	cout<<"\nsorted array:";
	for(int i=0;i<n;++i)
		cout<<"\t"<<a[i];
	return 0;
}
