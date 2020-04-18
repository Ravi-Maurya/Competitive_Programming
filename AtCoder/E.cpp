#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
 
long long int knapsack(vector<long long int>& wt, vector<long long int>& val, int n, int Weight, long long int sum){
    vector<vector<long long int>> dp(n+1, vector<long long int>(sum+1, INT_MAX));
    dp[0][0] = 0;
    long long int ans = 0;
    for(long long int i=1; i<=n; i++){
        for(long long int j=0; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=val[i-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-val[i-1]] + wt[i-1]);
            if(i==n && dp[i][j]<=Weight)
                ans = max(ans,j);
        }
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n, w;
    long long int sum = 0;
    cin>>n>>w;
    vector<long long int> wt(n), val(n);
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
        sum += val[i];
    }
    cout<<knapsack(wt, val, n, w, sum)<<endl;
    return 0;
}