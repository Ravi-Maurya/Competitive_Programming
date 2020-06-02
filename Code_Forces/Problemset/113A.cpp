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

bool compare(pll& a, pll& b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<pll> arr(n);
    rep(n)
        cin>>arr[i].first>>arr[i].second;
    sort(arr.begin(), arr.end(), compare);
    ll res=  0;
    rep(n){
        if((arr[i].first == arr[k-1].first) && (arr[i].second == arr[k-1].second))
            res++;
    }
    cout<<res<<"\n";
    return 0;
}