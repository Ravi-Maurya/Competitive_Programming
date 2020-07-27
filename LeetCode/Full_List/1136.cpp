class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> indegree(N+1,0);
        vector<unordered_set<int>> graph(N+1);
        for(auto& arr: relations){
            graph[arr[0]].insert(arr[1]);
            indegree[arr[1]]++;
        }
        queue<int> q;
        for(int i=1;i<=N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int res = 0;
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            if(size!=0)
                res++;
            while(size--){
                auto curr = q.front();q.pop();
                count++;
                for(auto v: graph[curr]){
                    if(indegree[v]>0){
                        indegree[v]--;
                        if(indegree[v]==0)
                            q.push(v);
                    }
                }
            }
        }
        if(count==N)
            return res;
        return -1;
    }
};