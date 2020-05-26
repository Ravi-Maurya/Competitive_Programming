#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,d;
    cin>>n>>d;
    ll a,b;
    cin>>a>>b;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> min_heap;
    for(auto i=0; i<n;i++){
        ll x,y;
        cin>>x>>y;
        ll tmp = x*a + y*b;
        if(tmp<=d){
            min_heap.push({tmp,i+1});
        }
    }
    vector<ll> res;
    while(!min_heap.empty() && min_heap.top().first<=d){
        d -= min_heap.top().first;
        res.push_back(min_heap.top().second);
        min_heap.pop();
    }
    cout<<res.size()<<"\n";
    for(auto& a:res)
        cout<<a<<" ";
    cout<<((res.size()!=0)?"\n":"");
    return 0;
}