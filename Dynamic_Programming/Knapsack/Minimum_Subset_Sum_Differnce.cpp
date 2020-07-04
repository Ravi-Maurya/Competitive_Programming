#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve(vector<int>& num, int n){
    int S = 0,Sum;
    for(auto& x: num)
        S += x;
    Sum = ceil(S/2.0);
    int dp[n+1][Sum+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=Sum; j++){
            if(num[i-1]<=j)
                dp[i][j] = max(dp[i-1][j],num[i-1] + dp[i-1][j-num[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return {dp[n][Sum], S- dp[n][Sum]};
}

int main(){
    return 0;
}