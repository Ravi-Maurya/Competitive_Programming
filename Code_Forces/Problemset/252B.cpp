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
    ll n,v;
    cin>>n>>v;
    vector<ll> a(n),b(n);
    rep(n){
        cin>>a[i]>>b[i];
    }
    ll days = 0;
    ll res = 0;
    for(int d=1;d<=3001; d++){
        int curr = 0;
        for(int i=0;i<n;i++)
            if(a[i]==d)
                curr += b[i];
        if(curr + days <= v){
            res += days + curr;
            days = 0;
        }
        else{
            res += v;
            int t = v - days;
            if(t<0)
                t = 0;
            days = curr- t;
        }
    }
    cout<<res<<"\n";

    return 0;
}