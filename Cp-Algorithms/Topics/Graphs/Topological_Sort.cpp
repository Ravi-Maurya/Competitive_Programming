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

int n;
vector<vector<int>> adjList;
vector<bool> visited;
vector<int> res;

void dfs(int u){
    visited[u] = true;
    for(int v: adjList[u]){
        if(!visited[v])
            dfs(v);
    }
    res.push_back(u);
}

vector<int> topsort(){//DFS
    visited.assign(n,false);
    res.clear();
    for(int u =0; u<n; u++)
        if(!visited[u])
            dfs(u);
    reverse(res.begin(),res.end());
    return res;
}

vector<int> topological_sort(int V){//BFS
    vector<int> inDegree(V,0);
    for(int u=0; u<V; u++)
        for(auto v: adjList[u])
            inDegree[v]++;
    
    queue<int> q;
    for(int u=0; u<V; u++)
        if(inDegree[u]==0){
            q.push(u);
            inDegree[u]--;
        }
    vector<int> topSort;
    while (!q.empty()){
        int u = q.front();
        q.pop;
        topSort.push_back(u);
        for(auto v: adjList[u]){
            inDegree[v]--;
            if(inDegree[v]==0){
                q.push(v);
                inDegree[v]--;
            }
        }
    }
    if(topSort.size() != V)//Cycle exists
        return {};
    return topSort;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}