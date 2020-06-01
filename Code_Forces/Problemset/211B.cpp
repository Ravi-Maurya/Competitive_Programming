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
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    rep(n){
        cin>>arr[i];
    }
    rep(n-1){
        arr[i+1] += arr[i];
    }
    ll idx = -1;
    ll res = INT_MAX;
    for(ll i = 0; i<n-k+1; i++){
        ll j = i+k-1;
        ll curr = arr[j] - ((i==0)?0:arr[i-1]);
        if(curr<res){
            res = curr;
            idx = i;
        }
    }
    cout<<(idx+1)<<"\n";
    return 0;
}