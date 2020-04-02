int Solution::maxcoin(vector<int> & a) {
    int n = a.size();
    vector<int> tmp(n+1);
    vector< vector<int> > dp(n+1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        tmp[i + 1] = tmp[i] + a[i];
        dp[i][i] = a[i];
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            int j = i + k;
            dp[i][j] = tmp[j + 1] - tmp[i] - min(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    return dp[0][n - 1];
}