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
#define mod 100000000
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)

ll dp[101][101][11][11];
ll n1,n2,k1,k2;

ll recursive(ll f, ll h, ll prevf, ll prevh){
    if(f<0 || h<0)
        return 0;
    if(f==0 && h==0)
        return 1;
    if(dp[f][h][prevf][prevh] != -1)
        return dp[f][h][prevf][prevh];
    dp[f][h][prevf][prevh] = 0;
    if(prevf<k1)
        dp[f][h][prevf][prevh] += (recursive(f-1,h,prevf+1,0)%mod);
    if(prevh<k2)
        dp[f][h][prevf][prevh] += (recursive(f,h-1,0,prevh+1)%mod);
    dp[f][h][prevf][prevh] %= mod;
    return dp[f][h][prevf][prevh];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>n1>>n2>>k1>>k2;
    cout<< recursive(n1,n2,0,0) <<"\n";
    return 0;
}