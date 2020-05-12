#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int lcs(string a, string b){
    int m = a.size(), n = b.size();
    int dp[2][n+1];
    bool bi;
    for(int i=0; i<=m;i++){
        bi = i&1;
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[bi][j] = 0;
            else if (a[i-1]==b[j-1])
                dp[bi][j] = 1 + dp[1-bi][j-1];
            else
                dp[bi][j] = max(dp[1-bi][j-1], dp[bi][j-1]);
        }
    }
    return dp[bi][n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}