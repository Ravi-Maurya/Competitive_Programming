int Solution::maxProfit(const vector<int> &A) {
    int profit = 0;
    int n = A.size();
    if(n<=1)
        return profit;
    for(int i=1;i<n;i++){
        int curr_profit = A[i]-A[i-1];
        if(curr_profit>0)
            profit += curr_profit;
    }
    return profit;
}
