class Solution {
public:
    vector<bool> visited;
    vector<int> tin,low;
    vector<vector<int>> adjList;
    vector<vector<int>> res;
    int timer;
    
    void dfs(int u, int parent){
        visited[u] = true;
        tin[u] = low[u] = timer++;
        for(auto v: adjList[u]){
            if(v==parent)
                continue;
            if(visited[v])
                low[u] = min(low[u],tin[v]);
            else{
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v]>tin[u]){
                    res.push_back({u,v});
                }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        timer = 0;
        adjList.resize(n);
        visited.resize(n,0);
        tin.resize(n,-1);
        low.resize(n,-1);
        for(auto edge: connections){//O(E)
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1);
        return res;
    }
};