class Solution {
public:
    vector<vector<int>> dp;
    vector<int> sum;
    int solve(vector<int>& piles, int n, int m, int idx){
        int curr = 0;
        int res = 0;
        if(idx>=n)
            return 0;
        if(dp[idx][m]!=-1)
            return dp[idx][m];
        for(int i=idx, x=1; i<n && x<=2*m; i++,x++){
            curr += piles[i];
            int tmp = curr + solve(piles,n,max(m,x),i+1);
            if(tmp>res)
                res = tmp;
        }
        return dp[idx][m] = (sum[idx] - res);
    }
    int stoneGameII(vector<int>& piles) {
        int s = 0;
        int n = piles.size();
        dp.resize(n,vector<int>(3*n,-1));
        sum = vector<int>(n,0);
        sum[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--)
            sum[i] = sum[i+1] + piles[i];
        return sum[0] - solve(piles,n,1,0);
    }
};