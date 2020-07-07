class Solution {
public:
    long long int nthCatalan(int n){
        vector<long long int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++)
            for(int j=0; j<i; j++)
                dp[i] = dp[i] + dp[j]*dp[i-j-1];
        return dp[n];
    }
    int numTrees(int n) {
        return nthCatalan(n);
    }
};