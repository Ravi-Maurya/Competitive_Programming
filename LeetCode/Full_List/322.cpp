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


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long int>> dp(n+1,vector<long long int>(amount+1));
        for(int i=1; i<=n; i++)
            dp[i][0] = 0;
        dp[0][0] = INT_MAX;
        for(int j=1;j<=amount; j++){
            dp[0][j] = INT_MAX;
            if(j%coins[0] == 0)
                dp[1][j] = j/coins[0];
            else
                dp[1][j] = INT_MAX;
        }
        for(int i=2; i<=n; i++){
            for(int j=1; j<=amount;j++){
                if(coins[i-1]<=j)
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (dp[n][amount]>=INT_MAX?-1:dp[n][amount]);
    }
};


class Solution {
public:
    void dfs(vector<int>& coins, int amount, int& res, int cnt, int idx){
        if(amount == 0){
            res = min(res, cnt);
            return;
        }
        if(idx == coins.size())   return;
        int n = coins[idx];
        for(int k = amount/n; k >= 0 && cnt + k < res; k--)
            dfs(coins, amount-n*k, res, cnt+k, idx+1);
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX;
        int idx = 0;
        int cnt = 0;
        sort(coins.rbegin(), coins.rend());
        dfs(coins, amount, res, cnt, idx);
        return res == INT_MAX ? -1 : res;
    }
};