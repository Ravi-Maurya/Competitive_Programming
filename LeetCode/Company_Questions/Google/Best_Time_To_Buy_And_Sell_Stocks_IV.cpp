class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k>n/2){
            int res = 0;
            for(int i=0;i<n-1;i++)
                res += (prices[i+1]>=prices[i]?prices[i+1]-prices[i]:0);
            return res;
        }
        vector<vector<int>> dp(k+1,vector<int>(n+1,0));
        for(int i=1;i<=k;i++){
            int prev_diff = INT_MIN;
            for(int j=1;j<n;j++){
                int tmp = dp[i-1][j-1] - prices[j-1];
                if(prev_diff<tmp)
                    prev_diff = tmp;
                dp[i][j] = max(dp[i][j-1],prices[j]+prev_diff);
            }
        }
        return dp[k][n-1];
    }
};