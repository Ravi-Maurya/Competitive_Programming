#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n, int k){
    int dp[n];
    memset(dp,INT_MAX,sizeof(dp));
    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<i+k+1;j++)
            dp[j] = min({dp[j],dp[i] + abs(nums[i] - nums[j])});
    }
    return dp[n-1];
}

int main(){
    return 0;
}