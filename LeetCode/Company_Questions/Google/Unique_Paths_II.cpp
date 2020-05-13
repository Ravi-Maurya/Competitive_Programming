class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
};
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    if(A[0][0]==1 || A[m-1][n-1]==1)
        return 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==1)
                dp[i][j] = 0;
            else if(i==0 && j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = dp[i][j-1];
            else if(j==0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}
