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
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll i = (n/2);
    ll j = i+1;
    if(n&1)
        j++;
    ll min_index = n+1, max_index = -1;
    ll res = 0;
    while(i>=1){
        int curr = abs(s[i-1]-s[j-1]);
        curr = min(curr,26-curr);
        res += curr;
        if(curr!=0){
            if(i<min_index)
                min_index = i;
            if(i>max_index)
                max_index = i;
        }
        i--;
        j++;
    }
    if(p>=(n/2))
        p = n - p + 1;
    if(res!=0){
        res += max_index - min_index;
        res += min(abs(max_index - p), abs(min_index - p));
    }
    cout<<res<<"\n";
    return 0;
}