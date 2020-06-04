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
    cin>>n>>m;
    vector<ll> indegree(n+1,0);
    unordered_map<ll,set<ll>> graph;
    while(m--){
        ll u,v;
        cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    map<ll,set<ll>> prrr;
    unordered_set<ll> visited;
    rep(n){
        ll t;
        cin>>t;
        prrr[t].insert(i+1);
    }
    for(auto p: prrr){
        for(auto& u: p.second){
            visited.insert(u);
            if(graph.count(u)){
                for(auto& v: graph[u]){
                    if(p.second.count(v)){
                        cout<<-1<<"\n";
                        return 0;
                    }
                    if(!visited.count(v))
                        indegree[v]++;
                }
            }
        }
    }
    queue<ll> q;
    visited.clear();
    for(auto p: prrr){
        for(auto& i: p.second){
            if(indegree[i]==0){
                indegree[i]--;
                q.push(i);
                visited.insert(i);
            }
        }
    }
    if(q.empty()){
        cout<<-1<<"\n";
        return 0;
    }
    vector<ll> res;
    while(!q.empty()){
        auto u = q.front();q.pop();
        res.push_back(u);
        if(graph.count(u)){
            for(auto v:graph[u]){
                if(!visited.count(v)){
                    indegree[v]--;
                    if(indegree[v]==0){
                        indegree[v]--;
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
        }
    }
    if(res.size()!=n)
        cout<<-1<<"\n";
    else{
        for(auto x:res)
            cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}