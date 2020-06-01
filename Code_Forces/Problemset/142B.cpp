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

bool isprime(ll n){
    if(n==1)
        return false;
    if(n<4)
        return true;
    if(n%2==0 || n%3 ==0)
        return false;
    for(ll i = 4; i*i<=n; i++)
        if(n%i==0)
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    rep(n){
        ll t;
        cin>>t;
        if(t<4){
            cout<<"NO\n";
            continue;
        }
        ll sq = floor(sqrt(t));
        if((sqrt(t) - sq)== 0 && isprime(sq))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}