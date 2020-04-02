int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    vector<int> dp(1001,INT_MAX);
    dp[0]=0;
    for(int i =0; i<B.size();i++){
        if(B[i]==1){
            for(int j = 1; j<1001; j++)
                dp[j] = C[i]+dp[j-1];
            break;
        }
    }
    for(int i =0 ; i<B.size();i++){
        for(int j=B[i];j<1001;j++){
            dp[j] = min(dp[j],dp[j-B[i]] + C[i]);
        }
    }
    long long int ans=0;
    for(int i : A)
        ans += dp[i];
    return ans;
}
