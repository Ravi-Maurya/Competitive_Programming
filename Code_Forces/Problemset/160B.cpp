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
    // vector<ll> arr(n);
    ll sum = 0;
    ll non_post = 0;
    minheap(ll) pq;
    rep(n){
        ll t;
        cin>>t;
        pq.push(t);
        if(t<=0)
            non_post++;
    }
    if(k<=non_post){
        while(k--){
            ll t = pq.top();pq.pop();
            t *= -1;
            pq.push(t);
        }
    }
    else{
        k -= non_post;
        while(non_post--){
            ll t = pq.top();pq.pop();
            t *= -1;
            pq.push(t);
        }
        if(k&1){
            ll t = pq.top();pq.pop();
            t *= -1;
            pq.push(t);
        }
    }
    while (!pq.empty()){
        sum += pq.top();pq.pop();
    }
    
    // rep(n){
    //     cin>>arr[i];
    //     if(arr[i]<0)
    //         non_post++;
    // }
    // if(k<=non_post){
    //     rep(k)
    //         arr[i] *= -1;
    // }
    // else{
    //     rep(non_post)
    //         arr[i] *= -1;
    //     if(non_post)
    //         k -= non_post;
    //     sort(arr.begin(), arr.end());
    //     if(k&1)
    //         arr[0] *= -1;
    // }
    // rep(n)
    //     sum += arr[i];
    cout<<sum<<"\n";
    return 0;
}