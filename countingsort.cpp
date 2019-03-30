#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n],b[n+1];
	int count[k+1]={};
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		++count[a[i]];
	}
	
	for(int i=1;i<k+1;++i)
	{
		count[i]=count[i]+count[i-1];
	}
	
	for(int i=n-1;i>=0;--i)
	{
		b[count[a[i]]]=a[i];
		--count[a[i]];
	}
	cout<<"\nsorted array:";
	for(int i=1;i<n+1;++i)
		cout<<"\t"<<b[i];
	return 0;
}
