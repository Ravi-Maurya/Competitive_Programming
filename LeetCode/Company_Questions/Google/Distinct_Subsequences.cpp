class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,0));
        for(int j=0; j<=n; j++)
            dp[0][j] = 1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                dp[i][j] = dp[i][j-1];
                if(s[j-1]==t[i-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        return dp[m][n];
    }
};