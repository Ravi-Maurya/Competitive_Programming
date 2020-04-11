#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1)
            cout<<"1"<<"\n"<<"1 1"<<endl;
        else if(n==2)
            cout<<"1"<<"\n"<<"2 1 2"<<endl;
        else if(n==3)
            cout<<"1"<<"\n"<<"3 1 2 3"<<endl;
        else{
            cout<< floor(n/2) <<"\n"<<"3 1 2 3"<<"\n";
            for(int i=4; i<n ; i+=2)
                cout<<"2 "<<i<<" "<<(i+1)<<"\n";
            if(n%2==0)
                cout<<"1"<<" "<<n<<endl;
        }
        
    }

    return 0;
}