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

vector<vector<int>> adjList;
vector<int> tin,low;
vector<bool> visited;
vector<bool> cutvertex;
vector<int> res;
int timer;

void dfs(int u, int parent){//O(V+E)
    visited[u] = true;
    tin[u] = low[v] = timer++;
    int children = 0;
    for(int v: adjList[u]){
        if(v==parent)
            continue;
        if(visited[v])
            low[u] = min(low[u],tin[v]);
        else{
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>=tin[u] && parent!=-1)
                cutvertex[u] = true;
            ++children;
        }
    }
    if(parent==-1 && children>1)
        cutvertex[u] = true;
}

void find_cutpoints(int n){
    timer = 0;
    visited.resize(n,0);
    tin.resize(n,-1);
    low.resize(n,-1);
    for(int i=0;i<n; i++)
        if(!visited[i])
            dfs(i,-1);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}