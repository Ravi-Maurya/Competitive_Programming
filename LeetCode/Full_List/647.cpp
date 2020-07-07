class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        int res = n;
        for(int length=2; length<=n; length++){
            for(int i=0; i<n-length+1; i++){
                int j = i+length-1;
                dp[i][j] = (s[i]==s[j]);
                if(length>2){
                    dp[i][j] = dp[i][j] && dp[i+1][j-1];
                }
                
                if(dp[i][j])
                    res++;
            }
        }
        return res;
    }
};