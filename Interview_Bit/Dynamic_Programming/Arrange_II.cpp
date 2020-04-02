vector<vector<int>> dp;

int rec(int horse, int stable, string A, int K){
    int n = A.size();
    if (horse == n) {
        if (stable == K)
            return 0;
        return INT_MAX;
    }
    
    if (stable == K)
        return INT_MAX;
    
    if (dp[horse][stable] != -1)
        return dp[horse][stable];
    
    int W = 0, B = 0, res = INT_MAX;
    
    for (int i = horse; i < n; ++i){
        W += (A[i] == 'W');
        B += (A[i] == 'B');
        if (W * B > res)
            break;
        int tmp = rec(i + 1, stable + 1, A, K);
        if (tmp != INT_MAX)
            res = min(res, tmp + (W * B));
    }
    return dp[horse][stable] = res;
}

int Solution::arrange(string A, int B) {
    int n =A.size();
    dp.clear();
    dp.resize(n,vector<int>(B,-1));
    int res = rec(0,0,A,B);
    return res==INT_MAX ? -1 : res;
}
