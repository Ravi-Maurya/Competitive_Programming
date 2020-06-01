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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    unordered_set<ll> visited;
    rep(m){
        ll u,v;
        cin>>u>>v;
        visited.insert(u);
        visited.insert(v);
    }
    ll i = 1;
    for(;i<=n; i++){
        if(!visited.count(i))
            break;
    }
    cout<<(n-1)<<"\n";
    for(ll j=1; j<=n; j++)
        if(j!=i){
            if(i<j)
                cout<<i<<" "<<j<<"\n";
            else
                cout<<j<<" "<<i<<"\n";
        }
    return 0;
}