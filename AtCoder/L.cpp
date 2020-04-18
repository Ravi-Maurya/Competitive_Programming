#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<vector<long long>> dp(n+1,vector<long long>(n+1));
    for(int i=n-1; i>=0;i--){
        for(int j=i;j<n;j++){
            if(j==i)
                dp[i][j] = arr[i];
            else
                dp[i][j] = max(arr[i] - dp[i+1][j], arr[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}