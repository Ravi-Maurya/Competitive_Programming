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

ll give(ll l, ll r,vector<vector<ll>>& dp){
    if(l==0)
        return dp[r][r];
    ll rs = (dp[r][r] - dp[l-1][r] - dp[r][l-1] + dp[l-1][l-1]);
    return rs;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    ll n = s.size();
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(ll length = 1; length<=n; length++){
        for(ll i = 0; i<n-length+1; i++){
            ll j = i+length - 1;
            if(length == 1){
                dp[i][j] = 1;
            }
            else if(length == 2){
                dp[i][j] = ((s[i]==s[j])?1:0);
            }
            else{
                if(dp[i+1][j-1]==1 && (s[i]==s[j]))
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
    }
    for(ll i = 0; i<n; i++)
        for(ll j = 1; j<n; j++)
            dp[i][j] += dp[i][j-1];
    for(ll j = 0; j<n; j++)
        for(ll i = 1; i<n; i++)
            dp[i][j] += dp[i-1][j];
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<< give(l,r,dp) << "\n";
    }
    return 0;
}