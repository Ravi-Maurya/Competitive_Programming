class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0, stock = -prices[0];
        for(int i=1; i<prices.size(); i++){
            profit = max(profit,stock+prices[i]-fee);
            stock = max(stock,profit-prices[i]);
        }
        return profit;
    }
};