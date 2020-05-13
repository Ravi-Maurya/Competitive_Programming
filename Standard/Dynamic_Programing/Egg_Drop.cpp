#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int egg_drop(int n, int floors){
    vector<vector<int>> dp(n+1,vector<int>(floors+1,0));
    for(int i=1; i<=n; i++)
        dp[i][1] = 1;
    for(int j=1;j<=floors; j++)
        dp[1][j] = j;
    for(int i=2; i<=n; i++){
        for(int j=2; j<=floors; j++){
            dp[i][j] = INT_MAX;
            for(int k=1; k<=j; k++){
                int tmp = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                if(tmp<dp[i][j])
                    dp[i][j] = tmp;
            }
        }
    }
    return dp[n][floors];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}