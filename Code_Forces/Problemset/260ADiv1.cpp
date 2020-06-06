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
// const ll N = 1e5;
// ll n;
// ll a[N+5];
// ll ans;

ll max(ll t, ll p){
    if(t<p)
        return p;
    return t;
}

// void recursive(ll idx, unordered_set<ll> ust, ll curr){
//     if(idx>n){
//         ans = max(ans,curr);
//         return;
//     }
//     unordered_set<ll> tmp = ust;
//     if(!ust.count(a[idx])){
//         curr += a[idx];
//         tmp.insert(a[idx]+1);
//         tmp.insert(a[idx]-1);
//         recursive(idx+1,tmp,curr);
//         curr -= a[idx];
//     }
//     recursive(idx+1,ust,curr);
//     return;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL); cout.tie(NULL);
//     ans = -1;
//     cin>>n;
//     for(ll i = 1; i<=n; i++){
//         cin>>a[i];
//     }
//     unordered_set<ll> ust;
//     recursive(1,ust,0);
//     cout<<ans<<"\n";
//     return 0;
// }
const ll N = 1e5;
ll a[N+5],dp[N+5];
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    cin>>n;
    ll max_num = -1;
    rep(n){
        ll t;
        cin>>t;
        if(t>max_num)
            max_num = t;
        a[t]++;
    }
    dp[1] = a[1]*1;
    dp[2] = max(dp[1],a[2]*2);
    for(ll i = 3; i<=max_num; i++){
        dp[i] = max(dp[i-1],a[i]*i + dp[i-2]);
    }
    cout<<dp[max_num]<<"\n";
    return 0;
}

