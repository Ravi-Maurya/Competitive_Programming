#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll unsigned long long int
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
    return a.first<=b.first;
}

ll min(ll& a, ll& b){
    if(a<b)
        return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,r,avg;
    cin>>n>>r>>avg;
    ll sum = 0;
    ll comp = n*avg;
    vector<pll> arr(n);
    rep(n){
        ll marks,essay;
        cin>>marks>>essay;
        sum += marks;
        arr[i] = {essay,r-marks};
    }
    if(comp-sum<=0){
        cout<<0<<"\n";
        return 0;
    }
    sort(arr.begin(),arr.end(),compare);
    ll diff = comp-sum;
    ll essays = 0;
    for(ll i= 0; i<n; i++){
        if(diff<=0){
            break;
        }
        ll curr = min(diff,arr[i].second);
        essays += (arr[i].first * curr);
        diff -= curr;
    }
    cout<< essays<<"\n";
    return 0;
}