void rec(vector<vector<int>>& dp, vector<int>& res, int i, int j, vector<int> B){
    if(i+1==j)
        return;
    for(int k=i+1;k<j;k++){
        if(dp[i][k]+dp[k][j]+B[j]-B[i] == dp[i][j]){
            res.push_back(B[k]);
            rec(dp,res,i,k,B);
            rec(dp,res,k,j,B);
            return;
        }
    }
    return;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    B.push_back(0);
    B.push_back(A);
    sort(B.begin(),B.end());
    int n = B.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int length =2;length<=n;length++){
        for(int i=0;i<n-length+1;i++){
            int j = i+length-1;
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+B[j]-B[i]);
            }
        }
    }
    vector<int> res;
    rec(dp,res,0,n-1,B);
    return res;
}
