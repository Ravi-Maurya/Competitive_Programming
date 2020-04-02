#define mod 1000007
int Solution::coinchange2(vector<int> &A, int B) {
    vector<long int> dp(B+1,0);
    dp[0] = 1;
    int n = A.size();
    for(int i=0;i<n;i++){
        vector<long int> tmp(B+1,0);
        tmp[0] = 1;
        for(int j=1;j<=B;j++){
            tmp[j] = dp[j]%mod;
            if(j-A[i]>=0)
                tmp[j] = tmp[j]%mod + tmp[j-A[i]]%mod;
            tmp[j] %= mod;
        }
        dp = tmp;
    }
    return dp[B];
}
