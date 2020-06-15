class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while(!q.empty()){
            auto u = q.front();q.pop();
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
                return false;
        return true;
    }
};