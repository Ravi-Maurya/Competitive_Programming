#include<bits/stdc++.h>
using namespace std;

int solve(string& a, int m){
    if(m==0)
        return 0;
    int dp[m+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==a[j-1] && i!=j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    // print lrs
    int length = dp[m][m];
    int l = dp[m][m];
    string res(l);
    int n = m;
    while(m>0 && n>0){
        if(dp[m-1][n-1]+1 == dp[m][n]){
            res[--l] = a[m-1];
            m--;
            n--;
        }
        else if(dp[m-1][n]>=dp[m][n-1])
            m--;
        else
            n--;
    }
    cout<< res;
    return length;
}



int main(){
    return 0;
}