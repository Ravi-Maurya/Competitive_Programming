class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int u = q.front();q.pop();
            if(graph[u].empty() && u!=destination)
                return false;
            for(int v: graph[u]){
                if(indegree[v]<0)
                    return false;
                indegree[v]--;
                q.push(v);
            }
        }
        return true;
    }
};