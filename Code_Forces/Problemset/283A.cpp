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
    int n;
    cin>>n;
    vector<int> arr(n),diff(n-1),left(n-1),right(n-1);
    rep(n)
        cin>>arr[i];

    for(int i = 0; i<n-1; i++){
        diff[i] = arr[i+1] - arr[i];
    }
    left[0] = -1;
    right[n-2] = -1;
    for(int i=1;i<n-1; i++){
        left[i] = max(left[i-1],diff[i-1]);
        right[n-i-2] = max(right[n-i-1],diff[n-i-1]);
    }
    int res = INT_MAX;
    for(int i=0; i<n-2; i++){
        int j = i+1;
        int t = diff[i] + diff[j];
        res = min(res, max({left[i],right[j],t}));
    }
    cout<<res<<"\n";
    return 0;
}