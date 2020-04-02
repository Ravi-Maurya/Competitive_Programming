int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(A[i]>A[j] && dp[i]<dp[j]+1)
                dp[i] = dp[j] + 1;
    int res = 1;
    for(int i=1;i<n;i++)
        res = max(res,dp[i]);
    return res;
}
