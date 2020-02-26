#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,r;
    cout<<"Input The Number of Process: ";cin>>p;
    cout<<"Input The Number of Resources: ";cin>>r;
    int All[p][r],Max[p][r];
    int Need[p][r],Ava[r];
    int Finish[p];

    cout<<"Process \tAllocation \tMax"<<endl;
    cout<<"________________________________________"<<endl;
    /**Input Allocation and Max**/
    for(int i=0; i<p; i++){
        cout<<"P"<<i<<"\t\t";
        for(int j=0; j<r; j++){
            cin>>All[i][j];
        }
        for(int j=0; j<r; j++){
            cin>>Max[i][j];
        }
        Finish[i] = -1;
    }
    cout<<"Available: ";
    /**Input Available**/
    for(int i=0; i<r; i++){
        cin>>Ava[i];
    }

    /**Finding Need**/
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            Need[i][j] = Max[i][j]-All[i][j];
        }
    }

    int S = 0;
    while(1){
        ///Copying Available
        int Temp[r];
        for(int i=0; i<r; i++){
            Temp[i] = Ava[i];
           // cout<<Temp[i]<<' ';
        }//cout<<endl;

        for(int I = 0; I<p; I++){
            ///Check Process Finish True of False
            int Ck1 = 0;
            for(int i=0; i<p; i++){
                if(Finish[i] == I){Ck1++; break;}
            }if(Ck1 != 0){continue;}

            ///Checking Available
            int AvaF = 0;
            for(int i=0; i<r; i++){
                if(Need[I][i] > Ava[i]){AvaF++; break;}
            }if(AvaF != 0)continue;

            for(int i=0; i<r; i++){
                Ava[i] += All[I][i];
            }
            Finish[S++] = I;
        }
        ///check process
        int Ck2=0,Ck3=0;
        for(int i=0; i<p; i++){
            if(Finish[i] < 0){Ck2 = 0; break;}
            Ck2 = 1;
        }if(Ck2 == 1)break;
        for(int i=0; i<r; i++){
            if(Temp[i] != Ava[i]){Ck3 = 1; break;}
        }
        if(Ck2 == 0 && Ck3 == 0){cout<<endl<<"Deadlock Occurs..........!!!"<<endl;return 0;}
    }
    cout<<endl;
    cout<<"DeadLock not Occurs.....!"<<endl;
    cout<<"Seq: <";
    for(int i=0; i<p; i++){
        cout<<' '<<'P'<<Finish[i];
    }cout<<" >"<<endl;

    return 0;
}
