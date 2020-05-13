#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int recursive(vector<int>& arr, int i, int sum){
    if(sum==0)
        return 1;
    if(sum<0)
        return 0;
    if(i<=0 && sum>0)
        return 0;
    return recursive(arr,i-1,sum) + recursive(arr,i,sum-arr[i]);
}

int coins(vector<int>& arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
    for(int j=0; j<=sum; j++)
        dp[0][j] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1])
                dp[i][j] += dp[i][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}