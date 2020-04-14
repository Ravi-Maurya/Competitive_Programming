// Knapsack with precomputation

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,k,p;
        cin>>n>>k>>p;
        vector<vector<int>> nstacks(n,vector<int>(k));
        int dp[n+1][p+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            memcpy(dp[i+1], dp[i], sizeof(dp[0]));
            for(int j=0,s=0;j<k;j++){
                cin>>nstacks[i][j];
                s += nstacks[i][j];
                for(int x=0;x+j+1<=p;x++){
                    dp[i+1][x+j+1] = max(dp[i][x]+s,dp[i+1][x+j+1]);
                }
            }
        }
        cout<<"Case #"<<test<<": "<<dp[n][p]<<"\n";
    }
    return 0;
}