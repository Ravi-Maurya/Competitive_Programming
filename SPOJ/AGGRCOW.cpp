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

ll n,c;

bool check(ll mid, vector<ll>& arr){
    ll cows = 1, position = arr[0];
    for(ll i = 1; i<n; i++){
        if(arr[i]-position >= mid){
            cows++;
            if(cows == c)
                return true;
            position = arr[i];
        }
    }
    return false;
}

ll aggresive(vector<ll>& arr){
    ll low =0 , high = arr[n-1], max = -1;
    while(low<high){
        ll mid = (low + high)/2;
        if(check(mid,arr)){
            if(mid>max)
                max = mid;
            low = mid+1;
        }
        else
            high = mid;
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    for(ll test = 1; test<=t; test++){
        cin>>n>>c;
        vector<ll> arr(n);
        rep(n)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll res = aggresive(arr);
        cout<<res<<"\n";
    }
    return 0;
}