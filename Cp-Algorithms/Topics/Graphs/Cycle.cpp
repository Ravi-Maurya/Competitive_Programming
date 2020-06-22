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
vector<char> color;
vector<int> parent;
vector<int> res;
int cycle_start, cycle_end,n;

bool dfs(int u){
    color[u] = 1;
    for(int v: adjList[u]){
        if(color[v]==0){
            parent[v] = u;
            if(dfs(v))
                return true;
        }
        else if(color[v]==1){
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

bool cycle(){//O(E)
    color.assign(n,0);
    parent.assign(n,-1);
    cycle_start = -1;
    for(int u = 0; u<n; u++)
        if(color[u]==0 && dfs(u))
            break;
    if(cycle_start == -1){
        return false;
    }
    for(int u = cycle_end; u!=cycle_start; u = parent[u])
        res.push_back(u);
    res.push_back(cycle_start);
    reverse(res.begin(),res.end());
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}