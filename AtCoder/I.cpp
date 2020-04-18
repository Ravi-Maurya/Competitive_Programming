#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<long double> arr(n+1);
    vector<vector<long double>> dp(n+1,vector<long double>(n+1,0));
    for(int i=1; i<=n;i++)
        cin>>arr[i];
    dp[0][0] = 1;
    for(int i=1; i<=n;i++){
        for(int j=0; j<=i; j++){
            dp[i][j] = dp[i-1][j]*(1.00000 - arr[i]);
            if(j>0)
                dp[i][j] += dp[i-1][j-1]*arr[i];
        }
    }
    long double ans = 0;
    for(int i=0; i<=n; i++){
        if(i>n-i)
            ans += dp[n][i];
    }
    cout<<fixed<<setprecision(15)<<ans<<"\n";
    return 0;
}