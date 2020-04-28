class Solution {
public:
    bool isMatch(string A, string B) {
        int n = A.size();
        int m = B.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=1;j<=m;j++)
            if(B[j-1]=='*')
                dp[0][j] = dp[0][j-2];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1] || B[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                else if(B[j-1]=='*'){
                    dp[i][j] = dp[i][j-2];
                    if(A[i-1]==B[j-2] || B[j-2]=='.')
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        return dp[n][m];
    }
};