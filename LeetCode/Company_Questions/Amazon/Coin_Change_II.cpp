class Solution {
public:
    int change(int amount, vector<int>& coins) {
	    vector<int> dp(1 + amount);
	    dp[0] = 1;
	    for (int c = 1; c <= coins.size(); c++) {
		    for (int s = 1; s <= amount; s++) {
			    if (s == coins[c-1])
                    dp[s] += 1;
			    if (s - coins[c-1] > 0)
                    dp[s] += dp[s - coins[c-1]];
		    }
	    }
	    return dp[amount];
    }
};