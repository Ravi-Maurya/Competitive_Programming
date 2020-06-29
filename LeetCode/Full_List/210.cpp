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


class Solution {// Optimized aapproach
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<int> ans;
        int n=prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<n;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0)
                q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(int i=0;i<graph[u].size();i++){
                if(indegree[graph[u][i]]==0)
                    return {};
                indegree[graph[u][i]]--;
                if(indegree[graph[u][i]]==0)
                    q.push(graph[u][i]);
            }
        }
        if(ans.size()!=numCourses)
            return {};
        return ans;
    }
};