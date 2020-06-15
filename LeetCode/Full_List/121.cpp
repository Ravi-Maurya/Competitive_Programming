class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        if(n<2)
            return res;
        int mn = prices[0];
        for(int i=1; i<n; i++){
            res = max(res, prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        return res;
    }
};