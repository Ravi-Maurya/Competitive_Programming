#include<bits/stdc++.h>
using namespace std;

int ks(vector<int>& wt, vector<int>& val, int n, int W){//can use memoization
    if(n==0 || W==0)
        return 0;
    if(wt[n-1]<=W)
        return max(val[n-1] + ks(wt, val, n-1, W-wt[n-1]), ks(wt, val, n-1, W));
    return ks(wt, val, n-1,W);
}

int solve(vector<int>& wt, vector<int>& val, int n, int W){
    int dp[n+1][W+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(wt[i-1]<=j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main(){
    return 0;
}