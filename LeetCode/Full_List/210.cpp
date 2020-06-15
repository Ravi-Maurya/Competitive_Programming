class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0)
            return {};
        vector<int> indegree(numCourses,0);
        unordered_map<int,unordered_set<int>> graph;
        for(auto& p: prerequisites){
            int u = p[1];
            int v = p[0];
            graph[u].insert(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 0 ;i<numCourses; i++)
            if(indegree[i]==0){
                q.push(i);
                indegree[i]--;
            }
        vector<int> res;
        while(!q.empty()){
            auto u = q.front();q.pop();
            res.push_back(u);
            if(graph.count(u)){
                for(auto& v: graph[u]){
                    if(indegree[v]>0){
                        indegree[v]--;
                        if(indegree[v] == 0){
                            q.push(v);
                            indegree[v]--;
                        }
                    }
                }
            }
        }
        for(int i=0; i<numCourses; i++)
            if(indegree[i]>=0)
                return {};
        return res;
    }
};