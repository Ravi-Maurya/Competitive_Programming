int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    if(m==1 && B[0]=='*')
        return true;
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int j=1;j<=m;j++)
        if(B[j-1]=='*')
            dp[0][j] = dp[0][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1] || B[j-1]=='?')
                dp[i][j] = dp[i-1][j-1];
            else if(B[j-1]=='*')
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
        }
    // cout<<dp[n][m]<<n<<m<<endl;
    return dp[n][m];
}
