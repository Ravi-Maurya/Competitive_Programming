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

vector<pll> adjListWeighted;
ll n,s,t;

ll dijkstra(ll source, ll dest){ // O(Elog(V))
    minheap(pll) pq;
    vector<ll> distance(n,inf);
    pq.push(make_pair(0,source));
    distance[source] = 0;
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        auto destination =  adjListWeighted[u];
        ll v = destination.second;
        ll wt = destination.first;
        if(v!=-1){
            if(distance[v]> distance[u]+wt){
                distance[v] = distance[u] + wt;
                pq.push(make_pair(distance[v],v));
            }
            if(v==dest)
                return distance[v];
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    adjListWeighted.clear();
    cin>>n;
    adjListWeighted.resize(n,{-1,-1});
    cin>>s>>t;
    rep(n){
        ll v,u = (i+1);
        cin>>v;
        if(u!=v)
            adjListWeighted[u-1] = {1,v-1};
    }
    if(s==t){
        cout<<0<<"\n";
        return 0;
    }
    cout<< dijkstra(s-1,t-1) << endl;
    return 0;
}