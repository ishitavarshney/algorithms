#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;++i)
		cin>>a[i];
	
	for(int i=0;i<n;++i)
	{
		int pos=i,min=a[i];
		for(int j=i+1;j<n;++j)
		{
			if(a[j]<=min)
			{
				pos=j;
				min=a[j];
			}
			
		}
		int t=a[pos];
		a[pos]=a[i];
		a[i]=t;
	}
	cout<<"\nsorted array:";
	for(int i=0;i<n;++i)
		cout<<"\t"<<a[i];
	return 0;
}
