#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    map<ll,ll> mp;
    for(ll i=0; i<n; i++){
        ll tmp;
        cin>>tmp;
        mp[tmp]++;
    }
    ll diff = mp.rbegin()->first - mp.begin()->first;
    ll times;
    if(mp.size()>1)
        times = mp.rbegin()->second * mp.begin()->second;
    else
        times = (mp.begin()->second * (mp.begin()->second - 1))/2;
    cout<<diff<<" "<<times<<"\n";
    return 0;
}