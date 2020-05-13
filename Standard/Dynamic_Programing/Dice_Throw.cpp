#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int find_ways(int m, int n, int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0] = 1
    // for(int j=1;j<=sum && j<=m; j++)
    //     dp[1][j] = 1;
    // for(int i=2; i<=n; i++){
    //     for(int j=1;j<=sum; j++){
    //         for(int k=1;k<=m && k<j;k++)
    //             dp[i][j] += dp[i-1][j-k];
    //     }
    // }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=sum;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            if(j>m)
                dp[i][j] -= dp[i-1][j-m-1];
        }
    }
    return dp[n][sum];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}