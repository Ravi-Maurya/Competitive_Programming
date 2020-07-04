#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& num, int Sum, int n ){
    bool dp[n+1][Sum+1];
    memset(dp,false,sizeof(dp));
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=Sum; j++){
            if(num[i-1]<=j)
                dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][Sum];
}

int main(){
    return 0;
}