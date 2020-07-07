class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        int res = 0;
        for(int i=0;i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]==1)
                    res++;
                
                if(i==0 || j==0)
                    dp[i][j] = matrix[i][j];
                else if(matrix[i][j]==1){
                    int tmp = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    dp[i][j] = tmp + 1;
                    res += tmp;
                }
            }
        }
        return res;
    }
};