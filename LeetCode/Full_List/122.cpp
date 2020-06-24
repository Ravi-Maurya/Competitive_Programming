class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        if(n<2)
            return res;
        for(int i=1; i<n; i++){
            if(prices[i-1]<prices[i])
                res += prices[i]-prices[i-1];
        }
        return res;
    }
};