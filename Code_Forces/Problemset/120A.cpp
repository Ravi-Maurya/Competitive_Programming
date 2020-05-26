#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    if(n==0 && m!=0){
        cout<<"Impossible\n";
        return 0;
    }
    cout<<max(n,m)<<" ";
    cout<<(n+m-(m==0?0:1))<<"\n";
    return 0;
}