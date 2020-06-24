class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int val = amount+1;
        vector<int> dp(val,val);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j]<=i)
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};

class Solution {
public:
    vector<int> dp;
    int recursion(vector<int>& coins, int amount){
        if(amount<0)
            return -1;
        if(amount==0)
            return 0;
        if(dp[amount-1]!=0)
            return dp[amount-1];
        int minval = INT_MAX;
        for(auto x: coins){
            int res = recursion(coins,amount-x);
            if(res>=0 && res<minval)
                minval = res+1;
        }
        dp[amount-1] = (minval==INT_MAX)?-1:minval;
        return dp[amount-1];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)
            return 0;
        dp.resize(amount,0);
        return recursion(coins,amount);
    }
};