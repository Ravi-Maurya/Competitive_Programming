#define mod 1000000007
long long int dp[51][51];
long long int nCr[51][51];

int Solution::cntPermBST(int A, int B) {
    memset(dp,0,sizeof(dp));
    memset(nCr,0,sizeof(nCr));
    nCr[0][0] = dp[0][0] = dp[1][0] = 1;
    for(int i=1;i<=A;i++){
        nCr[i][0] = 1;
        for(int j=1;j<=i;j++)
            nCr[i][j] = (nCr[i-1][j-1]%mod + nCr[i-1][j]%mod)%mod;
    }
    for(int i=2;i<=A;i++){
        for(int j=1;j<=i;j++){
            int left = max(j-1,1);
            int right = max(i-j,1);
            long long int tmp = 0, p = nCr[i-1][j-1];
            for(int k=0;k<left;k++){
                tmp = (tmp%mod + dp[i-j][k]%mod)%mod;
                dp[i][k+1] = (dp[i][k+1]%mod + (((dp[j-1][k]*tmp)%mod)*p)%mod)%mod;
            }
            tmp = 0;
            for(int k=0;k<right;k++){
                dp[i][k+1] = (dp[i][k+1]%mod + (((dp[i-j][k]*tmp)%mod)*p)%mod)%mod;
                tmp = (tmp%mod + dp[j-1][k]%mod)%mod;
            }
        }
    }
    return dp[A][B]%mod;
}
