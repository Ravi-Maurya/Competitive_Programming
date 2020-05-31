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

ll convert(ll n){
    ll digits = log10(n) + 1;
    ll res = 0;
    while(digits--){
        ll div = pow(10,digits);
        ll t = n/div;
        n = n%div;
        // cout<<t<<" "<<n<<" p\n";
        if(t!=0){
            res = res*10 + t;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b;
    cin>>a>>b;
    ll prev = a+b;
    a = convert(a);
    b = convert(b);
    prev = convert(prev);
    // cout<<a<<" "<<b;
    cout<<((a+b == prev)?"YES\n":"NO\n");
    return 0;
}