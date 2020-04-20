#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<vector<int>> matrix(n,vector<int>(n)), dp(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j =0;j<n; j++)
                cin>>matrix[i][j];
        dp[0] = matrix[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = matrix[i][j] + (max({j-1>=0?dp[i-1][j-1]:0, dp[i-1][j], j+1<n?dp[i-1][j+1]:0}));
            }
        }
        cout<<*max_element(dp[n-1].begin(), dp[n-1].end())<<"\n";
    }
    return 0;
}