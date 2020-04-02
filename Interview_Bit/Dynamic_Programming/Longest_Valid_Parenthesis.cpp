int Solution::longestValidParentheses(string A) {
    int n = A.size();
    if(n<=1)
        return 0;
    int res = 0;
    vector<int> dp(n,0);
    for(int i=1;i<n;i++){
        if(A[i]==')' && i-dp[i-1]-1>=0 && A[i-dp[i-1]-1]=='('){
            dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2]: 0);
            res = max(res,dp[i]);
        }
    }
    return res;
}
