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

ll a,b,c;

ll s(ll x){
    if(x<0)
        return -1;
    ll res = 0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return res;
}


bool check(ll x){
    ll res = (b*pow(s(x),a) + c - x);
    return (res==0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin>>a>>b>>c;
    vector<ll> res;
    for(ll S=1; S<=81; S++){
        ll x = b*pow(S,a) + c;
        if(s(x)==S && x<1e9){
            res.push_back(x);
        }
    }
    cout<<(res.size())<<"\n";
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}