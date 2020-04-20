#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int s = 0, n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            s+=arr[i];
        }
        if(s&1 == 1){
            cout<<"NO\n";
            continue;
        }
        s = (s>>1);
        vector<vector<bool>> dp(n+1, vector<bool>(s+1));
        for(int i=0; i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=s;i++)
            dp[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1; j<=s; j++){
                if(j<arr[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        if(dp[n][s])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}