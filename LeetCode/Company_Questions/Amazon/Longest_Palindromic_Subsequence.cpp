int lps(string s){
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int res = 1;
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(int length = 2; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            if(s[i]==s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
            res = max(res,dp[i][j]);
        }
    }
    return res;
}

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return lps(s);
    }
};