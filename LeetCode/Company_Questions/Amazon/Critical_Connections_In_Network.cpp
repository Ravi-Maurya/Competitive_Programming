#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// Critical Connections > edges
class Solution1 {
public:
    void dfs(int cur, int parent, int& dep, vector<vector<int>>& adjList, vector<vector<int>>& bridges, vector<int>& depth, vector<int>& lowLink, vector<bool>& visited) {
    visited[cur] = true;
    depth[cur] = lowLink[cur] = ++dep;
    
    for(auto to: adjList[cur]) {
        if(to == parent) continue;
        if(!visited[to]) {
            dfs(to, cur, dep, adjList, bridges, depth, lowLink, visited); 
            lowLink[cur] = min(lowLink[cur], lowLink[to]);
            if(depth[cur] < lowLink[to]) bridges.push_back({cur, to}); 
        } else lowLink[cur] = min(lowLink[cur], depth[to]);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adjList(n), bridges;
    for(auto i: connections) {
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);  
    }
    vector<int> depth(n), lowLink(n);
    vector<bool> visited(n);
    int dep = 0;
    dfs(0, -1, dep, adjList, bridges, depth, lowLink, visited);
    return bridges;
}
};

#define INF 0x3f3f3f3f
class Solution2 {
public:
    
    vector < vector <int> > adj, bridges;
    vector <bool> visited; 
    
    vector <int> disc, low;
    
    void dfs(int u, int parent)
    {
        static int tim = 1;
        disc[u] = low[u] = tim++;
        int child = 0;
        visited[u] = true;
        
        for(auto ele: adj[u])
        {
            if(!visited[ele])
            {
                child++;
                dfs(ele, u);
                low[u] = min(low[u], low[ele]);
                if(low[ele] > disc[u])
                {
                    vector <int> temp;
                    temp.push_back(u);
                    temp.push_back(ele);
                    bridges.push_back(temp);
                }
            }
            else if (ele != parent)
            {
                low[u] = min(low[u], disc[ele]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        adj.resize(n);
        
        for(int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
                
        visited.resize(n, false);
        disc.resize(n, INF);
        low.resize(n, INF);
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                dfs(i, -1);
        }
                
        return bridges;
    }
};