#include<bits/stdc++.h>
using namespace std;

int main()
{   cout<<"Enter how many Process: ";
    int n;cin>>n;
    int PR[n],AT[n],BT[n];
    int P[n],A[n],B[n],loc[n];
    cout<<"PR "<<"AT "<<"BT "<<endl;
    for(int i=0; i<n; i++){
        char c;cin>>c;
        cin>>PR[i];
        cin>>AT[i];A[i]=AT[i];
        cin>>BT[i];
    }

    sort(A,A+n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i]==AT[j])loc[i]=j;
        }
    }

    for(int i=0; i<n; i++){
        P[i] = PR[loc[i]];
        B[i] = BT[loc[i]];
    }

    PR[0] = A[0]+B[0];
    for(int i=0; i<n; i++){
        PR[i+1] = PR[i]+B[i+1];
    }

    for(int i=0; i<n; i++){
        AT[i] = PR[i]-A[i];
        BT[i] = AT[i]-B[i];
    }

    cout<<endl<<"CPU Scheduling:"<<endl;
    cout<<"PR\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT"<<endl;
    cout<<"--------------------------------------------"<<endl;
    for(int i=0; i<n; i++){
        cout<<'P'<<P[i]<<'\t';
        cout<<A[i]<<'\t'; cout<<B[i]<<'\t';
        cout<<PR[i]<<'\t';cout<<AT[i]<<'\t';
        cout<<BT[i]<<endl;
    }

    return 0;
}
