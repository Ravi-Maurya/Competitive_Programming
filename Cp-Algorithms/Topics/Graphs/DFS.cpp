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

unordered_map<int,set<int>> adjList;
unordered_set<int> visited;
vector<int> res;
void recursive_dfs(int u){ //O(V+E)
    visited.insert(u);
    res.push_back(u);
    for(int v:adjList[u]){
        if(!visited.count(v))
            recursive_dfs(v);
    }
    return;
}

void dfs(int u){
    stack<int> s;
    s.push(u);
    while(!s.empty()){
        u = s.top();s.pop();
        if(!visited.count(u)){
            res.push_back(u);
            visited.insert(u);
            for(int v: adjList[u])
                if(!visited.count(v))
                    s.push(v);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}