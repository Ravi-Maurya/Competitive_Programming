#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
int knapsack(int w, int n, vector<int>& wt, vector<int>& val){
    vector<vector<int>> dp(n+1,vector(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1; j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=wt[i-1])
                dp[i][j] = max(dp[i][j],
                            val[i-1] + dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}