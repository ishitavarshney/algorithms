#include <iostream>
#include<limits.h>

using namespace std;



int main()
{
   int n,q;
   cout<<"\nenter no. of processes";
   cin>>n;
    cout<<"\nenter time quantum";
   cin>>q;
   int At[n],bt[n],tat[n],wt[n],ct[n],T=0,b[n],B=0;
   float awt=0,atat=0;

   cout<<"\nenter arrival times";
   for(int i=0;i<n;++i)
   {
       cin>>At[i];
   }
   cout<<"\nenter burst times";
     for(int i=0;i<n;++i)
   {
       cin>>bt[i];
       b[i]=bt[i];
       B+=bt[i];
   }
    T=At[0];
   while(T<B)
   {

      for(int i=0;i<n;++i)
      {
        T=(T>At[i])?T:At[i];
          if((At[i]<=T)&&(b[i]>0))
          {
              if(b[i]<=q)
              {
                  T+=b[i];
                  b[i]=0;
                  ct[i]=T;
                  tat[i]=ct[i]-At[i];
                  wt[i]=tat[i]-bt[i];
                  atat+=tat[i];
                  awt+=wt[i];
              }
              else
              {
                  T+=q;
                  b[i]-=q;
              }

          }

      }

   }
   awt/=n;
   atat/=n;

   cout<<"\nPno.\tAT\tBT\tCT\tTAT\tWT";
   for(int i=0;i<n;++i)
   {
       cout<<"\n"<<i+1<<"\t"<<At[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i];
   }

   cout<<"\nAverage turnaround time:"<<atat<<"\nAverage waiting time:"<<awt;

    return 0;
}

