class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int S =0 , Sum;
        int n = stones.size();
        for(auto& stone: stones)
            S += stone;
        Sum = ceil(S/2.0);
        int dp[n+1][Sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=Sum; j++){
                if(stones[i-1]<=j)
                    dp[i][j] = max(dp[i-1][j], stones[i-1] + dp[i-1][j - stones[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return abs(S - 2*dp[n][Sum]);
    }
};
/*
e.g. -> [a,b,c,d]
1. (a,b) -> a-b if a>=b
    (c,d) -> c-d if c>=d
    (a-b,c-d) -> (a-b)-(c-d) if (a-b)>=(c-d) -> i.e. a+d - (b+c)
    So its differntiating the array in two subset such that there difference should be as minimum as possible
*/