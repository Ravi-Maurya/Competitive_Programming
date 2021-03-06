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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    rep(n)
        cin>>arr[i];
    ll m;
    ll l =0, w1 = 0, h1 = 0;
    cin>>m;
    while(m--){
        ll w2,h2;
        cin>>w2>>h2;
        l = max(l+h1, arr[w2-1]);
        w1 = w2;
        h1 = h2;
        cout<< l <<"\n";
    }
    return 0;
}