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

unsigned ll recursive(unsigned ll n){
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    unsigned ll k = floor(log2(n));
    unsigned ll add = pow(2,k+1)-1;
    n -= pow(2,k);
    return (add+recursive(n));
}

unsigned ll solve(unsigned ll n){
    unsigned ll res = 0;
    while(n){
        ll mask = n&~(n-1);
        ll tmp = mask;
        mask <<= 1;
        mask -= 1;
        res += mask;
        n -= tmp;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll test;
    cin>>test;
    rep(test){
        unsigned ll n;
        cin>>n;
        // cout<<recursive(n)<<"\n";
        cout<<solve(n)<<"\n";
    }
    return 0;
}