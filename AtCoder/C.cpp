#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<long long int>> dp(n+1, vector<long long int>(3,0));
    for(int i=0;i<n;i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        dp[i+1][0] = a + max(dp[i][1], dp[i][2]);
        dp[i+1][1] = b + max(dp[i][0], dp[i][2]);
        dp[i+1][2] = c + max(dp[i][1], dp[i][0]);
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
    return 0;
}