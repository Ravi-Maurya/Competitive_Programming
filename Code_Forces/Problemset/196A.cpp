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
    int n,m;
    cin>>n>>m;
    vector<int> arr(m);
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int res = INT_MAX;
    for(int i=0; i<m-n+1;i++){
        // cout<<m<<" "<<(i+n-1)<<"\n";
        res = min(res,arr[i+n-1] - arr[i]);
        // cout<<i<<" "<<res<<"\n";
    }
    cout<<res<<"\n";
    return 0;
}