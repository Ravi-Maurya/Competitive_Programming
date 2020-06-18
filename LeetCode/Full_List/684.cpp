class Solution {
public:
    int n;
    vector<vector<int>> graph;
    bool bfs(int u, int v){
        vector<bool> visited(n+1,false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()){
            int curr = q.front();q.pop();
            for(auto& nxt:graph[curr]){
                if(!((curr==u && nxt==v) || (curr==v && nxt==u)) && !visited[nxt]){
                    visited[nxt]=true;
                    q.push(nxt);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        graph.clear();
        graph.resize(n+1);
        for(auto& edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=n-1; i>=0; i--){
            if(bfs(edges[i][0],edges[i][1]))
                return edges[i];
        }
        return {};
    }
};