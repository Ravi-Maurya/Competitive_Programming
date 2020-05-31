#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll res = 0, curr = 1;
    for(int i=0;i<q;i++){
        ll t;
        cin>>t;
        // cout<<curr<<" "<<t<<"\n";
        if(curr<=t){
            res += (t-curr);
        }
        else{
            res += (n - (curr-t));
        }
        curr = t;
    }
    cout<<res<<"\n";
    return 0;
}