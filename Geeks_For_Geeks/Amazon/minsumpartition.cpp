#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,sum=0;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
            sum+=vec[i];
        }
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int j=1;j<=sum;j++)
            dp[0][j] = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
                if(vec[i-1]<=j)
                    dp[i][j] = dp[i][j] || dp[i-1][j-vec[i-1]];
            }
        int res =INT_MAX;
        for(int j = sum/2; j>=0; j--)
            if(dp[n][j]){
                res = sum-2*j;
                break;
            }
        cout<<res<<"\n";
        
    }
    return 0;
}