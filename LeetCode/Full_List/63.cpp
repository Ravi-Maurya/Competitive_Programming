class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = (obstacleGrid[i][j]==0)?dp[i][j-1]:0;
                else if(j==0)
                    dp[i][j] = (obstacleGrid[i][j]==0)?dp[i-1][j]:0;
                else
                    dp[i][j] = (obstacleGrid[i][j]==0)?(dp[i-1][j] + dp[i][j-1]):0;
            }
        }
        return dp[m-1][n-1];
    }
};