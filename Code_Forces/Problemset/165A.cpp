#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        double can = (360*1.0)/(180-x);
        if((can - floor(can))==0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
    return 0;
}