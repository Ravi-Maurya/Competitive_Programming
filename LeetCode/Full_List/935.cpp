const int mod = 1e9 + 7;
class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> moves = {
                {4,6},
            {6,8}, {7,9}, {4,8},
            {3,9,0},{},{1,7,0},
            {2,6},{1,3}, {2,4}
        };
        int dp[N+1][10];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<10; i++)
            dp[1][i] = 1;
        for(int i=2; i<=N; i++){
            for(int j=0; j<10; j++){
                for(int k:moves[j]){
                    dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
                }
            }
        }
        int res = 0;
        for(int i=0; i<10; i++)
            res = (res+dp[N][i])%mod;
        return res;
    }
};