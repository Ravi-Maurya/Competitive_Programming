#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
const int maxn = 1+10e5;

vector<bool> visited(maxn,false);
vector<vector<int>> edges(maxn);
vector<long long int> dp(maxn);

void dfs(int u){
    visited[u] = 1;
    for(int v: edges[u]){
        if(!visited[v])
            dfs(v);
        
        dp[u] = max(dp[u],dp[v]+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
    }
    for(int i=1; i<=n;i++)
        edges[0].push_back(i);
    dfs(0);
    cout<<dp[0]-1<<endl;   
    return 0;
}