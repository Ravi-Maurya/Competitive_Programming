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

vector<set<int>> adjList;
unordered_set<int> visited;
vector<int> tin, low;
int timer;

void dfs(int u, int parent){//O(V+E)
    visited.insert(u);
    tin[u] = low[u] = timer++;
    for(int v: adjuList[u]){
        if(v==parent)
            continue;
        if(visited.count(v))
            low[u] = min(low[u],tin[v]);
        else{
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>=tin[u]){
                // u and v is the bridge edge.
            }
        }
    }
}

void find_bridges(int V){
    timer = 0;
    visited.clear();
    tin.assign(V,-1);
    low.assign(V,-1);
    for(int i=0; i<v; i++)
        if(!visited.count(i))
            dfs(i,-1);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}