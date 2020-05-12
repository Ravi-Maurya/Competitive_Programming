#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
int game(vector<int> arr){
    int n = arr.size(),j;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i] = arr[i];
        if(i<n-1)
            dp[i][i+1] = max(arr[i],arr[i+1]);
    }
    for(int length = 3; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            j = i+length-1;
            dp[i][j] = max(arr[i] + min(dp[i+2][j],dp[i+1][j-1]), arr[j] + min(dp[i][j-2],dp[i+1][j-1]));
        }
    }
    return dp[0][n-1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<game(arr);
    return 0;
}