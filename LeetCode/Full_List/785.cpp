class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n,-1);
        queue<int> q;
        bool flag = true;
        for(int u= 0; u<n; u++){
            if(check[u]==-1){
                q.push(u);
                check[u] = 0;
                while(!q.empty()){
                    auto curr = q.front();q.pop();
                    for(auto v: graph[curr]){
                        if(check[v]==-1){
                            check[v] = check[curr] ^ 1;
                            q.push(v);
                        }
                        else{
                            flag &= check[curr]!=check[v];
                        }
                    }
                }
            }
        }
        return flag;
    }
};