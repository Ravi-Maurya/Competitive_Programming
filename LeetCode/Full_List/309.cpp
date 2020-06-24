// elements of choice for ith day
// dp[i][0] = Not stocking on ith day;
// dp[i][1] = stocking;
// for not stocking i.e. either previus one or  i am selling today so 
// dp[i-1][0] or dp[i-1][1] + prices[i]//to sell i had to stocked it on previous days
// for stocking i.e. either previus one or  i am buying today with cooldown of one day so
// dp[i-1][1] or dp[i-2][0] - prices[i]//to buy i had not to be stocked on previous days;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        if(n<2)
            return 0;
        if(n==2)
            return max(0,prices[1]-prices[0]);
        vector<vector<int>> dp(n,vector<int>(2));
        // dp[x][0] = I am not sotcking i.e either previous one or i am selling today
        // dp[x][1] = I am stocking i.e either previous one or i am buying today
        dp[0][0] = 0;// first day not stocking i.e. selling  or previous
        dp[0][1] = -prices[0];// sotcking at day1
        dp[1][0] = max(dp[0][1]+prices[1],dp[0][0]);//either prev or selling
        dp[1][1] = max(dp[0][1],-prices[1]);//stocking at day2
        for(int i=2; i<n; i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};