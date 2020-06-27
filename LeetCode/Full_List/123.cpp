class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int n = prices.size();
        vector<int> first(n,0);
        vector<int> second(n,0);
        int mn = prices[0];
        int mx = prices[n-1];
        int p = 0;
        for(int i=1;i<n; i++){
            if(prices[i]>mn)
                first[i] = prices[i]-mn;
            else
                mn = prices[i];
            p = max(p,first[i]);
            first[i] = p;
        }
        p = 0;
        for(int i=n-2; i>=0; i--){
            if(prices[i]<mx)
                second[i] = mx-prices[i];
            else
                mx = prices[i];
            p = max(p,second[i]);
            second[i] = p;
        }
        int res=  0;
        for(int i=0;i<n;i++){
            res = max(res,first[i]+second[i]);
        }
        return res;
    }
};