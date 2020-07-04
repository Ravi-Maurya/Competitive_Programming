#include<bits/stdc++.h>
using namespace std;

// Target Sum is Same question.
// Can be given as count of different assignments of +/- to given num array so that sum is diff.

int solve(vector<int>& num, int diff, int n){
    // abs(s1-s2) = diff, let s1>=s2
    // s1 - s2 = diff
    // s1 + s2 = S
    // 2*s1 = diff + S
    // s1 = (diff + S)/2
    // so we need to find count of subset with given sum = (diff + S)/2
    int Sum = 0;
    for(auto& x: num)
        Sum += x;
    Sum = (diff + Sum);
    if((Sum&1)!=0)
        return 0;
    Sum = Sum>>1;
    int dp[n+1][Sum+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=Sum; j++){
            if(num[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-num[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][Sum];
}

int main(){
    return 0;
}