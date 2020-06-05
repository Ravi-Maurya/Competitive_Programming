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

ll f(ll x){
    ll count = 0;
    while(x>=5 && x%5==0){
        x /= 5;
        count++;
    }
    while(x>=3 && x%3==0){
        x /= 3;
        count++;
    }
    while(x>=2 && x%2==0){
        x /= 2;
        count++;
    }
    if(x>2)
        return -1;
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<"\n";
        return 0;
    }
    ll gcd = __gcd(a,b);
    ll f1 = a/gcd;
    ll f2 = b/gcd;
    ll res = 0;
    res = f(f1);
    ll t = f(f2);
    // cout<< res<<" "<< t<< "\n";
    // cout<<f2;
    if(res==-1 || t==-1){
        cout<<-1<<"\n";
        return 0;
    }
    res += t;
    cout<<res<<"\n";
    return 0;
}