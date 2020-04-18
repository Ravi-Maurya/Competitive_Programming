#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    vector<int> dp(1<<n);
    dp[0] = 1;
    for(int mask = 0; mask<(1<<n)-1; mask++){
        int i = __builtin_popcount(mask);
        for(int j=0;j<n;j++){
            if(matrix[i][j] && !(mask&(1<<j))){
                int mask2 = mask^(1<<j);
                dp[mask2]+=dp[mask];
                if(dp[mask2]>=mod)
                    dp[mask2]-=mod;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}