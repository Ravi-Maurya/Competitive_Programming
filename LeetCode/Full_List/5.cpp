class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int idx = 0;
        int res = 0;
        for(int length=1; length<=n; length++){
            for(int i = 0; i<n-length+1; i++){
                int j = i+length-1;
                if(length==1){
                    dp[i][j] = 1;
                }
                else if(length == 2){
                    dp[i][j] = (s[i]==s[j]);
                }
                else{
                    dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                }
                
                if(dp[i][j] && length>res){
                    res = length;
                    idx = i;
                }
            }
        }
        return s.substr(idx,res);
    }
};