class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n<2)
            return n;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n; i++){
            dp[i][i] = 1;
        }
        int res = 1;
        for(int length = 2; length<=n; length++){
            for(int i=0; i<n-length+1; i++){
                int j = i+length-1;
                if(length==2 && s[i] == s[j])
                    dp[i][j] = 2;
                else if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};