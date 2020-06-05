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

ll nb,ns,nc,pb,ps,pc,r,cb = 0,cs = 0,cc = 0;

ll max(ll a, ll b){
    if(a>=b)
        return a;
    return b;
}

ll func(ll x){
    ll a = max(0, cb*x - nb)*pb;
    ll b = max(0, cs*x - ns)*ps;
    ll c = max(0, cc*x - nc)*pc;
    ll res = (a+b+c);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    for(auto ch: s){
        if(ch=='B')
            cb++;
        else if(ch=='S')
            cs++;
        else
            cc++;
    }
    ll low = 1, high = 1e13;
    ll res = 0;
    while(low<=high){
        unsigned ll mid = low + (high-low)/2;
        if(func(mid)<=r){
            low = mid+1;
            res = mid;
        }
        else
            high = mid-1;
    }
    cout<<res<<"\n";
    return 0;
}