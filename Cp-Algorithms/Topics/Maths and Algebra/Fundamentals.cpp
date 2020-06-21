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

ll power(ll a, ll n, ll m){//O(logn) m = modulous for exponent make it INT_MAX if no mod;
    ll res = 1;
    a %= m;
    if(a==0)
        return 0;
    while(n>0){
        if((n&1)==1)
            res = (res*a)%m;
        a = (a*a)%m;
        n >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll m){// assume m = prime; O(logm)
// if a,m = coprime i.e. gcd(a,m) = 1 use extended and return x in ax+my = 1
// if nor coprime then simple in O(m)
// if m = prime and coprime numbers then this one
    return power(a,m-2,m);
}

ll factorial(ll n, ll p){//O(plog(p,n)) log(a,b) = log (base a) b
    int res = 1;
    while(n>1){
        res = (res * ((n/p)%2==1?p-1:1))%p;
        for(int i=2;i<=n%p; i++)
            res = (res*i)%p;
        n /= p;
    }
    return res;
}

int gcd(int a, int b){//O(log(min(a,b)))
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int extended_gcd(int a, int b, int& x, int& y){// ax + by = gcd(a,b) is always true so find x,y;
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1){
        int quot = a1/b1;
        tie(x,x1) = make_tuple(x1,x-quot*x1);
        tie(y,y1) = make_tuple(y1,y-quot*y1);
        tie(a1,b1) = make_tuple(b1,a1 - quot*b1);
    }
    return a1;
}

pll fibonacci(int n){// returns Fn and F(n+1) in O(logn)
    if(n==0)
        return {0,1};
    auto p = fibonacci(n>>1);
    ll c = p.first * (2*p.second - p.first);
    ll d = p.first * p.first + p.second * p.second;
    if(n&1)
        return {d,c+d};
    return {c,d};
}

int gray_code(int n){// 000, 001, 011, 010, 110, 111, 101, 100, so G(4)=6
    return n^(n>>1);
}

int inverse_gray_code(int g){
    int n = 0;
    while(g){
        n ^= g;
        g >>= 1;
    }
    return n;
}

void BinomialCoff(int n, int r){
    ll C[n+1][r+1];
    C[0][0] = 1;
    for(int i=1; i<=n; i++){
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

void BinomialCoffmod(int n,  int r){// arbitrary Implentation
    int m;
    return (factorial(n,m) * modInverse(factorial(r,m),m)* modInverse(factorial(n-r,m),m))%m;
}

ll nthCatalan(int n){
    vector<ll> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] = (dp[i] + (dp[j]*dp[i-1-j]));
        }
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}