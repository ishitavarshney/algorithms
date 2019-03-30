#include <iostream>
#include<limits.h>

using namespace std;



int main()
{
   int n;
   cout<<"\nenter no. of processes";
   cin>>n;
   int At[n],bt[n],tat[n],wt[n],ct[n],T=0;
   float awt=0,atat=0;
   bool p[n]={};
   cout<<"\nenter arrival times";
   for(int i=0;i<n;++i)
   {
       cin>>At[i];
   }
   cout<<"\nenter burst times";
     for(int i=0;i<n;++i)
   {
       cin>>bt[i];
   }

   for(int i=0;i<n;++i)
   {
       T=(T>At[i])?T:At[i];
       int small=INT_MAX,pos;
       for(int j=0;At[j]<=T;++j)
       {
           if(!p[j])
           {
               if(bt[j]<=small)
               {
                   pos=j;
                   small=bt[j];
               }
           }
       }
       T=T+bt[pos];
       p[pos]=1;
       tat[pos]=T-At[pos];
       wt[pos]=tat[pos]-bt[pos];
       awt+=wt[pos];
       atat+=tat[pos];
       ct[pos]=T;
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
