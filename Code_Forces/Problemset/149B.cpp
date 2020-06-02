#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll long long int
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type,vector<type>,greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)

ll max(ll a, ll b){
    if(a>b)
        return a;
    return b;
}

ll min(ll a, ll b){
    if(a<b)
        return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    map<pll,ll> mp;
    rep(n){
        ll l,r;
        cin>>l>>r;
        mp[{l,r}] = i;
    }
    vector<pll> res;
    ll i = -1;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        if(it == mp.begin()){
            res.push_back(it->first);
            i++;
            continue;
        }
        if(res[i].second>= it->first.first){
            res[i].first = min(res[i].first, it->first.first);
            res[i].second = max(res[i].second, it->first.second);
        }
        else{
            res.push_back(it->first);
            i++;
        }
    }
    if(res.size()>1 || !mp.count(res[0])){
        cout<<-1<<"\n";
    }
    else{
        cout<<(mp[res[0]] + 1)<<"\n";
    }
    return 0;
}