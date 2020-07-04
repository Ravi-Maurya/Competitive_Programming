#include<bits/stdc++.h>
using namespace std;

int solve(string& a, int m, string& b, int n){
    if(n==0 || m==0)
        return 0;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    int res = 0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                res = max(res,dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return res;
}

int main(){
    return 0;
}