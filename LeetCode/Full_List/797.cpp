class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited;
    int n;
    void dfs(int curr, vector<vector<int>>& graph, vector<int>& tmp){
        if(curr== n-1){
            tmp.push_back(curr);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(curr);
        for(auto v: graph[curr]){
            if(!visited[v]){
                visited[curr] = 1;
                dfs(v,graph,tmp);
                visited[curr] = 0;
            }
        }
        tmp.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        visited.resize(n,false);
        vector<int> tmp;
        dfs(0,graph,tmp);
        return res;
    }
};