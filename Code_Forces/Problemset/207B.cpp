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
    ll n,m;
    unordered_set<int> ust,tmp;
    ust.insert(1);ust.insert(2);ust.insert(3);
    cin>>n>>m;
    vector<ll> res(n+1,0);
    while(m--){
        tmp = ust;
        ll a,b,c;
        cin>>a>>b>>c;
        if(res[a]==0 && res[b]==0 && res[c]==0){
            res[a] = 1;
            res[b] = 2;
            res[c] = 3;
        }
        else{
            if(res[a]!=0)
                tmp.erase(res[a]);
            if(res[b]!=0)
                tmp.erase(res[b]);
            if(res[c]!=0)
                tmp.erase(res[c]);
            if(tmp.size()){
                auto it = tmp.begin();
                if(res[a]==0){
                    res[a] = *it;
                    it++;
                }
                if(res[b]==0){
                    res[b] = *it;
                    it++;
                }
                if(res[c]==0){
                    res[c] = *it;
                }
            }
        }
    }
    for(ll i = 1;i <=n; i++)
        cout<<res[i]<<" ";
    cout<<"\n";
    return 0;
}