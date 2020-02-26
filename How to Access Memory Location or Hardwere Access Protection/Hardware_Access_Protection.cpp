#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Determine the CPU Error of not..?"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Enter The Number of Process: ";
    int process;cin>>process;
    int bus[process],limit[process];
    cout<<"Process\tBus\tLimit"<<endl;
    for(int i=0; i<process; i++){
        cout<<'P'<<i+1<<": \t";
        cin>>bus[i]>>limit[i];
    }cout<<endl;

    while(1){
        cout<<"Enter process no.: ";
        int i; cin>>i;
        cout<<"Enter CPU size: " ;
        int CPU; cin>>CPU;

        if(CPU>=bus[i-1] && (bus[i-1]+limit[i-1]) > CPU){
            cout<<"Memory Access......!"<<endl;continue;
        }cout<<"Error..........!"<<endl;
    }

    return 0;
}
