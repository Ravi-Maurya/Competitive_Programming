class Solution {
public:
    vector<int> dirs = {-1,0,1,0,-1};
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int& n, int& m){
        if(i<0 || i>=n || j<0 || j>=m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MIN;
        for(int k=0;k<4;k++){
            int nr = i + dirs[k];
            int nc = j + dirs[k+1];
            if(0<=nr && 0<=nc && nr<n && nc<m && (matrix[i][j] <matrix[nr][nc]))
                res = max(res,1+dfs(nr,nc,matrix,dp,n,m));
        }
        dp[i][j] = max(res,1);
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int res = 1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1)
                    dfs(i,j,matrix,dp,n,m);
                res = max(res,dp[i][j]);
            }
        return res;
    }
};