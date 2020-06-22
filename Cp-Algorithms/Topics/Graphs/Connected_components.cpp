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

unordered_map<int,unordered_set<int>> adjList;
unordered_set<int> visited;
vector<vector<int>> res;
vector<int> tmp;

void dfs(int u){
    visited.insert(u);
    tmp.push_back(u);
    for(int v: adjList[u]){
        if(!visited.count(v))
            dfs(v);
    }
    return;
}

void connected_comp(){//O(V+E)
    for(auto u :adjList){
        if(!visited.count(u.first)){
            tmp.clear();
            dfs(u.first);
            res.push_back(tmp);
        }
    }
    return;
}

// Can use DSU for VlogV complexity
// Work it in Online Fashion while inputing the edges

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}