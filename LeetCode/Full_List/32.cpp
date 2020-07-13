class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        if(n==0)
            return 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<n; i++){
            if(s[i]==')'){
                if(s[i-1]=='(')
                    dp[i] = ((i>=2)?dp[i-2]:0) + 2;
                else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(')
                    dp[i] = dp[i-1] +((i-dp[i-1]>=2)?dp[i-dp[i-1]-2]:0) + 2;
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};