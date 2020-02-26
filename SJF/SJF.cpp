#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    cout<<"Number of Values: ";
    int n;cin>>n;
    int Pr[n],Bt[n],Ct[n],Tat[n],Wt[n];
    int loc[n],b[n],c[n];
    cout<<"PR BT"<<endl;
    for(int i=0; i<n; i++){
        char c;cin>>c;
        cin>>Pr[i];
        cin>>Bt[i];
        b[i]=Bt[i];
    }
    cout<<"......................................"<<endl;
    sort(b,b+n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(b[i]==Bt[j])loc[i]=j;
        }
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += b[i];
        c[i]=sum;
    }

    for(int i=0; i<n; i++){
        Bt[loc[i]] = b[i];
        Ct[loc[i]] = c[i];
    }

    for(int i=0; i<n; i++){
        Tat[i] = Ct[i];
        Wt[i] = Tat[i]-Bt[i];
    }

    cout<<"PR\tBT\tCT\tTAT\tWT"<<endl;
    cout<<"......................................"<<endl;
    for(int i=0; i<n; i++){
        cout<<'P';
        cout<<Pr[i]<<'\t'<<Bt[i]<<'\t';
        cout<<Ct[i]<<'\t'<<Tat[i]<<'\t';
        cout<<Wt[i]<<endl;
    }

    return 0;
}
