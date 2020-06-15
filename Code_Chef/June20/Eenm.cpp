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

void solve(){
    ll n;
    cin>>n;
    if(n%2 != 0){
        for(ll i=1; i<=(n*n); i++){
            cout<<i<<" ";
            if(i%n==0)
                cout<<"\n";

        }
        return;
    }
    vector<ll> res(n+1);
    int straight = 1;
    for(ll i=1; i<=(n*n); i++){
        auto idx = ((i-1)%n);
        res[idx] = i;
        if((i%n) == 0){
            if(straight == 1){
                for(auto k = 0; k<n; k++){
                    cout << res[k] << " ";
                }
            }
            else{
                for(auto k = n - 1; k>=0; k--){
                    cout<<res[k]<<" ";
                }
            }
            straight = 1-straight;
            cout<<"\n";
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll test;
    cin>>test;
    for(ll t=0; t<test; t++){
        solve();
    }
    return 0;
}