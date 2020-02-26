#include <bits/stdc++.h>
using namespace std;
int ab;
typedef struct schedule
{
string pro_id;
int at,bt,ct,ta,wt;
}schedule;
bool compare(schedule a,schedule b)
{
return a.at < b.at;
}
bool compare2(schedule a,schedule b)
{
return a.bt < b.bt && a.at <= ab;
}
int main()
{
schedule pro[10];
int n,i,j;
cout<<"Enter the number of process:"<<endl;
cin>>n;
cout<<"Enter the process no., arrival time & burst time :"<<endl;
for(i=0;i<n;i++)
{
cin>>pro[i].pro_id;
cin>>pro[i].at;
cin>>pro[i].bt;
}
sort(pro,pro+n,compare);
pro[0].ct=pro[0].bt+pro[0].at;
pro[0].ta=pro[0].ct-pro[0].at;
pro[0].wt=pro[0].ta-pro[0].bt;
for(i=1;i<n;i++)
{
ab=pro[i-1].ct;
sort(pro+i,pro+n,compare2);
if(pro[i-1].ct<pro[i].at)
{
pro[i].ct=pro[i-1].ct+pro[i].bt+(pro[i].at-pro[i-1].ct);
}
else
{
pro[i].ct=pro[i-1].ct+pro[i].bt;
}
pro[i].ta=pro[i].ct-pro[i].at;
pro[i].wt=pro[i].ta-pro[i].bt;
}
cout<<"\nPn\t"<<"At\t"<<"Bt\t"<<"Ct\t"<<"TAT\t"<<"WT\t"<<endl;
for(i=0;i<n;i++)
{
cout<<"\n"<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].bt
<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<endl;
}
return 0;
}

