class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& dp){
        if(i>=j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for(int k=i; k<=j; k++){
            int tmp = k + max(solve(i,k-1,dp), solve(k+1,j,dp));
            if(res>tmp)
                res = tmp;
        }
        return dp[i][j] = res;
        
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};