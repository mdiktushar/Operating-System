#include<bits/stdc++.h>
using namespace std;\

int main()
{
    cout<<"number of value: ";
    int n;cin>>n;
    cout<<"Quantum time: ";
    int qt;cin>>qt;
    int b[n],c[n],wt[n];
    int B[n];

    for(int i=0; i<n; i++){
        cout<<"P"<<i+1<<'\t'<<"BT: ";
        cin>>b[i];B[i]=b[i];
    }

    int sum=0;
    int f=0;

    while(1){
        for(int i=0; i<n; i++){
            int m=0;
            if(b[i]==0){continue;}
            if(b[i]<qt){m=b[i];}
            else m = qt;
            sum += m;
            b[i] -= m;
            if(b[i]==0){c[i]=sum;f++;}
            if(f==n)break;
        }
        if(f==n)break;
    }
    cout<<"Pr\tBT\tCT\tWt"<<endl;
    cout<<".............................."<<endl;
    for(int i=0; i<n; i++){
        cout<<"P"<<i+1<<'\t';
        cout<<B[i]<<'\t'<<c[i]<<'\t'<<c[i]-B[i]<<endl;
    }

    return 0;
}
