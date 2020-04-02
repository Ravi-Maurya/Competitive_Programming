int Solution::solve(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    vector<vector<int>> dp(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0)
                dp[i][j] = A[i][j];
            else
                dp[i][j] = A[i][j]==0 ? 0: dp[i - 1][j] + 1;
        }
    }
    int res = 0;
    for(int i=0;i<r;i++){
        vector<int> tmp = dp[i];
        sort(tmp.rbegin(),tmp.rend());
        for(int j=0;j<c;j++)
            res = max(res, (j+1)*tmp[j]);
    }
    return res;
}
