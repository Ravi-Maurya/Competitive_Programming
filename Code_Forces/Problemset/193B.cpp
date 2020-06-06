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
    ll sum = 0;
    vector<ll> arr(n+1,0);
    for(ll i=1; i<=n; i++){
        ll t;
        cin>>t;
        sum += t;
        arr[i] = sum;
    }
    ll idx1 = k;
    ll idx2 = 2*k;
    ll max = (arr[idx1]-arr[idx1-k]) + (arr[idx2]-arr[idx2-k]);
    ll prev = (arr[idx1]-arr[idx1-k]);
    ll prev_id = idx1;
    for(ll j = 2*k+1; j<=n; j++){
        ll new_prev = arr[j-k] - arr[j-2*k];
        if(new_prev>prev){
            prev = new_prev;
            prev_id = j-k;
        }
        ll curr = arr[j]-arr[j-k];
        if(curr + prev > max){
            max = curr + prev;
            idx1 = prev_id;
            idx2 = j;
        }
    }
    cout<<(idx1-k+1)<<" "<<(idx2-k+1)<<"\n";
    return 0;
}