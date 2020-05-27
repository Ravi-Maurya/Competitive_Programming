#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll res = -1e18;
    for(auto i=0; i<n; i++){
        ll f,t;
        cin>>f>>t;
        ll curr = f;
        if(t>k){
            curr = curr-t+k;
        }
        res = max(res,curr);
    }
    cout<<res<<"\n";
    return 0;
}