long long int nthCatalan(int n){
    vector<long long int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] = (dp[i] + (dp[j]*dp[i-1-j]));
        }
    }
    return dp[n];
}
int Solution::numTrees(int A) {
    return nthCatalan(A);
}
