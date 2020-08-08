class Solution {
public:
    
    int bfs(unordered_map<int,unordered_set<int>>& graph, int n,vector<int>& arr){
        vector<bool> visited(n,false);
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0] = true;
        while(!q.empty()){
            int u = q.front().first;
            int d = q.front().second;
            q.pop();
            if(u-1>=0 && !visited[u-1]){
                q.push({u-1,d+1});
                visited[u-1] = true;
            }
            if(u+1<n && !visited[u+1]){
                if((u+1) == (n-1))
                    return d+1;
                q.push({u+1,d+1});
                visited[u+1] = true;
            }
            for(auto& v: graph[arr[u]]){
                if(!visited[v]){
                    if(v==n-1)
                        return d+1;
                    q.push({v,d+1});
                    visited[v] = true;
                }
            }
        }
        return 0;
    }
    
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 0;
        unordered_map<int,unordered_set<int>> graph;
        for(int i=0; i<n; i++){
            graph[arr[i]].insert(i);
        }
        // debug(graph);
        return bfs(graph,n,arr);
    }
};