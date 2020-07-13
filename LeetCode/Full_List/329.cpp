class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    int hashed(int r, int c, int n){
        return n*r + c;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int>> q;
        vector<int> indegree(n*m+1,0);
        vector<unordered_set<int>> graph(n*m+1);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int idx = hashed(i,j,n);
                for(int k=0;k<4;k++){
                    int nr = i + dirs[k];
                    int nc = j + dirs[k+1];
                    if(0<=nr && 0<=nc && nr<m && nc<n && matrix[nr][nc]<matrix[i][j]){
                        graph[hashed(nr,nc,n)].insert(idx);
                        indegree[idx]++;
                    }
                }
                if(indegree[idx]==0)
                    q.push({idx,1});
            }
        }
        int res = 0;
        while(!q.empty()){
            auto curr = q.front();q.pop();
            res = max(res,curr.second);
            for(auto v: graph[curr.first]){
                if(indegree[v]>0){
                    indegree[v]--;
                    if(indegree[v]==0)
                        q.push({v,curr.second+1});
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> dp;
    int res;
    int dirs[5] = {-1,0,1,0,-1};
    
    int dfs(int i, int j, vector<vector<int>>& matrix){
        if(dp[i][j]!=0)
            return dp[i][j];
        for(int k=0;k<4;k++){
            int nr = i + dirs[k];
            int nc = j + dirs[k+1];
            if(0<=nr && nr<matrix.size() && 0<=nc && nc<matrix[0].size() && matrix[nr][nc]>matrix[i][j])
                dp[i][j] = max(dp[i][j],dfs(nr,nc,matrix));
        }
        return ++dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        dp.resize(m,vector<int>(n,0));
        res = 0;
        for(int i=0;i<m; i++)
            for(int j=0; j<n; j++)
                res = max(res,dfs(i,j,matrix));
        return res;
    }
};