#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& len, vector<int>& price, int n, int N){
    int dp[n+1][N+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=N; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(len[i-1]<=j)
                dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][N];
}

int main(){
    return 0;
}