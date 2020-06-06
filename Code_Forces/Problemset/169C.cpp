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
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n+1,0),dp(n+1,0);
    for(ll i = 1; i<=n; i++)
        cin>>arr[i];
    while(q--){
        ll l,r;
        cin>>l>>r;
        dp[r]++;
        dp[l-1]--;
    }
    for(ll i = n-1; i>=0; i--)
        dp[i] += dp[i+1];
    sort(arr.begin(),arr.end());
    sort(dp.begin(),dp.end());
    ll res = 0;
    for(ll i =1; i<=n; i++){
        res += dp[i]*arr[i];
    }
    cout<<res<<"\n";
    return 0;
}