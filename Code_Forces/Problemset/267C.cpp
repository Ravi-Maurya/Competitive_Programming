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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> arr(n+1),pre(n+1,0);
    for(ll i=1; i<=n; i++){
        cin>>arr[i];
        pre[i] = arr[i] + pre[i-1];
    }
    vector<vector<ll>> dp(k+1,vector<ll>(n+1,-1));
    for(ll p=1; p<=k; p++){
        for(ll i = 1; i<=n; i++){
            ll res = -1;
            if(i-m >= 1 && dp[p-1][i-m]!=-1)
                res = max(res,pre[i]-pre[i-m] + dp[p-1][i-m]);
            if(i-m+1>=1 && p==1)
                res = max(res,pre[i]-pre[i-m]);
            if(i>1 && dp[p][i-1]!=-1)
                res = max(res,dp[p][i-1]);
            dp[p][i] = res;
        }
    }
    cout<< dp[k][n] <<"\n";
    return 0;
}