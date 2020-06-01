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
    vector<ll> arr(n),dp(n);
    rep(n){
        cin>>arr[i];
    }
    dp[n-1] = 1;
    unordered_set<ll> visited;
    visited.insert(arr[n-1]);
    for(ll i = n-2; i>=0; i--){
        dp[i] = dp[i+1];
        if(!visited.count(arr[i])){
            dp[i] += 1;
            visited.insert(arr[i]);
        }
    }
    rep(m){
        ll idx;
        cin>>idx;
        idx--;
        cout<<dp[idx]<<"\n";
    }
    return 0;
}