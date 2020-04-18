#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>0)
            arr[i] += arr[i-1];
    }
    vector<vector<long long>> dp(n+1,vector<long long>(n+1));
    for(int i=n-1; i>=0;i--){
        for(int j=i;j<n;j++){
            if(j==i)
                dp[i][j] = 0;
            else{
                long long int s = arr[j]-(i==0? 0: arr[i-1]);
                dp[i][j] = 1e18;
                for(int k=i;k<j;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}