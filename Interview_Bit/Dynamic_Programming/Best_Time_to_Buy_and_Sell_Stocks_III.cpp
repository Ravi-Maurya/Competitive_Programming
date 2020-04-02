int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n<=1)
        return 0;
    int total_profit = 0;
    vector<int> maxprofit_sell_at_i(n,0), maxprofit_buy_at_i(n,0);
    int buy = A[0], sell = A[n-1];
    for(int i=1;i<n;i++){
        buy = min(buy,A[i-1]);
        maxprofit_sell_at_i[i] = max(maxprofit_sell_at_i[i-1],A[i]-buy);
        
        sell = max(sell,A[n-i]);
        maxprofit_buy_at_i[n-i-1] = max(maxprofit_buy_at_i[n-i],sell-A[n-i-1]);
    }
    for(int i=0;i<n;i++)
        total_profit = max(total_profit, maxprofit_sell_at_i[i] + maxprofit_buy_at_i[i]);
    return total_profit;
}
