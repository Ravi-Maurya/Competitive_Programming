#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int Sum, int n){
    int dp[n+1][Sum+1];
    memset(dp,0,sizeof(dp));
    for(int j=0;j<=Sum;j++)
        dp[0][j] = INT_MAX - 1 ;
    for(int j=1; j<=Sum; j++){
        if(j%coins[0] == 0)
            dp[1][j] = j/coins[0];
        else
            dp[1][j] = INT_MAX - 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=Sum; j++){
            if(coins[i-1]<=j)
                dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j-coins[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][Sum];
}

int main(){
    return 0;
}