class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        int x = cuts.size();
        vector<vector<int>> dp(x+1,vector<int>(x+1,0));
        for(int length=2; length<=x-1; length++){
            for(int i=0; i<=(x-1-length); i++){
                int j = i + length;
                dp[i][j] = INT_MAX;
                for(int k=i+1; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
                }
            }
        }
        return dp[0][x-1];
    }
};