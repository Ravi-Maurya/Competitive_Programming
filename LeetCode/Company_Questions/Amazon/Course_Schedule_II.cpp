class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        // if(numCourses<2 || (numCourses==2 && prerequisites.size()<2))
        //     return true;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            int u = 0;
            for(;u < numCourses; u++)
                if(indegree[u]==0)
                    break;
            if(u == numCourses)
                return {};
            indegree[u] = -1;
            res.push_back(u);
            for(auto v: graph[u])
                indegree[v]--;
        }
        return res;
    }
};