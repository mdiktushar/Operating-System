#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"The Number of Values: ";
    int n; cin>>n;
    cout<<"P  BT Pro"<<endl;
    int pr[n],bt[n],pri[n],ct[n],wt[n];
    int loc[n],ri[n],b[n],c[n];
    for(int i=0; i<n; i++){
        char c;cin>>c;
        cin>>pr[i]>>bt[i]>>pri[i];
        ri[i]=pri[i];
    }

    sort(ri,ri+n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ri[i]==pri[j])loc[i]=j;
        }
    }

    for(int i=0; i<n; i++){
        b[i]=bt[loc[i]];
    }
    int sum=0;
    for(int i=0; i<n; i++){
        sum += b[i];
        ct[i] = sum;
    }

    for(int i=0; i<n; i++){
        ri[loc[i]]=ct[i];
    }
    for(int i=0; i<n; i++){
        wt[i]=ri[i]-bt[i];
    }
    cout<<"........................................."<<endl;
    cout<<"P\tBT\tPr\tCt\twt"<<endl;
    cout<<"........................................."<<endl;
    for(int i=0;i<n; i++){
        cout<<'P'<<pr[i]<<'\t';
        cout<<bt[i]<<'\t'<<pri[i]<<'\t'<<ri[i]<<'\t'<<wt[i]<<endl;
    }

    return 0;
}
