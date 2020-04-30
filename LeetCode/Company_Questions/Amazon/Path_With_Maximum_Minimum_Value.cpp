int solve(vector<vector<int>>& grid){
    int r = grid.size(),c=grid[0].size();
    vector<vector<int>> dp(r,vector<int>(c,0))
    dp[0][0] = INT_MAX;
    for(int i=1; i<r;i++)
        dp[i][0] = min(dp[i-1][0],grid[i][0]);
    for(int j=1; j<c;j++)
        dp[0][j] = min(dp[0][j-1],grid[0][j]);
    for(int i=1; i<r; i++){
        for(int j=1; j<c;j++){
            if(i==r-1 && j==c-1)
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j] = max(min(dp[i][j-1],grid[i][j]),min(dp[i-1][j],grid[i][j]));
        }
    }
    return dp[r-1][c-1];
}