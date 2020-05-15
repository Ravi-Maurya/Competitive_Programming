class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        queue<int> q;
        for(int u=0; u<numCourses; u++)
            if(indegree[u]==0){
                indegree[u] = -1;
                q.push(u);
            }
        while(!q.empty()){
            auto u = q.front();q.pop();
            res.push_back(u);
            for(auto v: graph[u]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        for(int u=0;u<numCourses;u++)
            if(indegree[u]>0)
                return {};
        return res;
    }
};