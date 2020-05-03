class Solution {
public:
    int maxProfit(vector<int>& prices) {
	    if(prices.empty())
		    return 0;
	    int bought1 = -1 * prices[0];
	    int sold1 = 0;
        int bought2 = INT_MIN;
	    int sold2 = 0;
        for(int i = 1; i < prices.size(); i++) {
		    bought1 = max(bought1, -1 * prices[i]);
		    sold1 = max(sold1, bought1 + prices[i]);
		    bought2 = max(bought2, sold1 - prices[i]);
		    sold2 = max(sold2, bought2 + prices[i]);
	    }
	    return sold2;
    }
};