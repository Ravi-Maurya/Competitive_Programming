int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n<=1)
        return 0;
    int buy = A[0];
    int profit = 0;
    for(int i=1;i<n;i++){
        buy = min(buy,A[i-1]);
        profit = max(profit,A[i]-buy);
    }
    return profit;
}
