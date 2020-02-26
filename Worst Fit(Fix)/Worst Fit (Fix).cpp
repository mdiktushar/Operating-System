#include<bits/stdc++.h>
using namespace std;

void input(int arr[],int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}
int main()
{
    cout<<"Number of Memory and Processes"<<endl;
    int n1,n2;cin>>n1>>n2;
    int mem[n1],pro[n2];
    cout<<"Memories in kb"<<endl;input(mem,n1);
    cout<<"Processes in kb"<<endl;input(pro,n2);
    cout<<endl;
    sort(mem,mem+n1);

    int unused = 0; int f=0;
    for(int i=0; i<n2; i++){
        int j=n1-1;
        for(; j>=0; j--){
            if(pro[i] <= mem[j]){
                unused += (mem[j]-pro[i]);
                cout<<"Process "<<i+1<<" allocated in "<<mem[j]<<endl;
                mem[j] = -1;
                break;
            }
        }
        if(j == -1){cout<<"Process "<<i+1<<" can't be allocated.....!!!"<<endl;f++;}
    }
    cout<<endl;
    cout<<"Internal Fragmentation: "<<unused<<endl;
    for(int i=0; i<n1; i++){
        unused += mem[i];
    }
    cout<<"Unused Space: "<<unused<<endl;
    if(f==0){cout<<"No External Fragmentation"<<endl;}
    else cout<<"External Fragmentation"<<endl;

    return 0;
}
