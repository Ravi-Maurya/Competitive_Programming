#define mod 1000000007
long long int nthCatalan(int n){
    vector<long long int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] = (dp[i]%mod + (dp[j]*dp[i-1-j])%mod)%mod;
        }
    }
    return dp[n];
}
int Solution::chordCnt(int A) {
    return nthCatalan(A);
}
