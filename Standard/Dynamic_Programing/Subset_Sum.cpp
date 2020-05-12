#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool subset_sum(vector<int>& arr, int sum){
    int n = arr.size();
    vector<vector<bool>> dp(n+1,vector(sum+1,false));
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1])
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    return dp[n][sum];
}

void print_subset(vector<int>& arr,int sum, int i, vector<int>& res, vector<vector<bool>>& dp){
    if(i==0 && sum!=0 && dp[0][sum]){
        res.push_back(arr[i]);
        cout<<res;
        return;
    }
    if(i==0 && sum==0){
        cout<<res;
        return;
    }
    if(dp[i-1][sum]){
        vector<int> tmp = res;
        print_subset(arr,i-1,sum,tmp,dp);
    }
    if(sum>=arr[i] && dp[i-1][sum-arr[i]]){
        res.push_back(arr[i]);
        print_subset(arr,i-1,sum-arr[i],res,dp);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}