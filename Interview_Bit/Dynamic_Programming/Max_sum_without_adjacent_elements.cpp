int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        if(i==0)
            dp[i] = max(A[0][i],A[1][i]);
        else if(i==1)
            dp[i] = max(dp[i-1],max(A[0][i],A[1][i]));
        else
            dp[i] = max(dp[i-1],dp[i-2]+max(A[0][i],A[1][i]));
    }
    return dp[n-1];
}
