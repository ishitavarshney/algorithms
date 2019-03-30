#include<iostream>
#include<limits>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1]={};
	a[0]=INT_MIN;
	for(int i=1;i<n+1;++i)
		cin>>a[i];
	
	for(int i=1;i<n+1;++i)
	{
		int pos=i,key=a[i];
		for(int j=i-1;j>=0;--j)
		{
			if(a[j]>a[i])
			{
				pos=j;
			}
		}
		for(int j=i;j>=pos+1;--j)
		{
			a[j]=a[j-1];
		}
		a[pos]=key;
	}
	cout<<"\nsorted array:";
	for(int i=1;i<n+1;++i)
		cout<<"\t"<<a[i];
	return 0;
}
