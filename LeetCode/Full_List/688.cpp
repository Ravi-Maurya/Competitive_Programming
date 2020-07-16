class Solution {
public:
    int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
    double knightProbability(int n, int K, int r, int c) {
        vector<vector<double>> dp(n,vector<double>(n,0));
        dp[r][c] = 1.0;
        while(K--){
            vector<vector<double>> dp2(n,vector<double>(n,0));
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int d=0; d<8; d++){
                        int nr = i + dx[d];
                        int nc = j + dy[d];
                        if(0<=nr && 0<=nc && nr<n && nc<n){
                            dp2[nr][nc] += dp[i][j]/8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double res = 0.0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                res += dp[i][j];
        return res;
    }
};