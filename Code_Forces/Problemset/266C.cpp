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
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n), cnt(n,0);
    rep(n){
        cin >> arr[i];
        sum += arr[i];
    }
    if((n<3) || (sum%3!=0)){
        cout<<0<<"\n";
        return 0;
    }
    sum /= 3;
    ll ss = 0;
    for(ll i = n-1; i>=0; --i){
        ss += arr[i];
        if(ss == sum)
            cnt[i] = 1;
    }
    for(ll i = n-2 ; i>=0 ; --i){
        cnt[i] += cnt[i+1];
    }
    ss = 0;
    ll res = 0;
    for(ll i = 0; (i+2)<n; ++i){
        ss += arr[i];
        if(ss == sum)
            res += cnt[i+2];
    }
    cout<< res <<"\n";
    return 0;
}