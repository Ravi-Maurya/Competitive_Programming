class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        vector<int> dp(n,0);
        for(int i=1; i<n; i++){
            if(s[i]==')'){
                if(s[i-1]=='(')
                    dp[i] = ((i>=2)?dp[i-2]:0) + 2;
                else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(')
                    dp[i] = dp[i-1] + ((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0)+2;
                res = max(res,dp[i]);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stck;
        stck.push(-1);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                stck.push(i);
            else{
                stck.pop();
                if(stck.empty())
                    stck.push(i);
                else
                    res = max(res,i-stck.top());
            }
        }
        return res;
    }
};