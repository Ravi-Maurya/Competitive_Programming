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
    ll n;
    ll res = 0;
    cin>>n;
    ll zeroes = 0, negones = 0;
    rep(n){
        ll t;
        cin>>t;
        if(t>0)
            res += (t-1);
        else if(t<0){
            res += abs(t+1);
            negones++;
        }
        else
            zeroes++;
    }
    res += zeroes;
    if((negones % 2 == 1) && (zeroes==0))
        res += 2;
    cout<< res<<"\n";
    return 0;
}