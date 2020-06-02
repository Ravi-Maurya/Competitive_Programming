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

ll nc3(ll n){
    ll num = 1;
    for(ll i =0; i<3; i++){
        num *= (n-i);
    }
    num /= 6;
    return num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n, d;
    cin>>n>>d;
    vector<ll> arr(n);
    rep(n)
        cin>>arr[i];
    unsigned ll res  = 0;
    rep(n-2){
        ll x = arr[i] + d;
        ll j = (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
        if(j==n || arr[j]!=x)
            j--;
        j -= i;
        if(j>0)
            res += ((j-1)*j)/2;
    }
    cout<<res<<"\n";
    return 0;
}