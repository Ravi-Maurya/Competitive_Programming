int Solution::solve(const vector<int> &A) {
    int sum = 0, n = A.size();
    for(int i=0;i<n;i++)
        sum += A[i];
    int tmp = sum/2;
    vector<int> dp(tmp+1, INT_MAX);
    dp[0] = 0;
    for(int i=0;i<n;i++)
        for(int j=tmp;j>=A[i];j--)
            if(dp[j-A[i]]!=INT_MAX)
                dp[j] = min(dp[j],dp[j-A[i]]+1);
    for(int j=tmp;j>=0;j--)
        if(dp[j]!=INT_MAX)
            return dp[j];
}
