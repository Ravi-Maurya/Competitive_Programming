#include<bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

int solve(string& a, int m, string& b, int n){// a ---(deletion)--> lcs ---(insertion)--> b
    if(n==0 || m==0)
        return 0;
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    int deletion = m -dp[m][n];
    int insertion = n- dp[m][n];
    return (deletion + insertion);
}