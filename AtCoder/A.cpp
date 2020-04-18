#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int solve(vector<int>& arr, vector<int>& dp, int n){
    dp[0] = 0;
    if(n==1)
        return dp[0];
    dp[1] = abs(arr[0]-arr[1]);
    if(n==2)
        return dp[1];
    for(int i=2;i<n;i++){
        dp[i] = min((dp[i-1]+abs(arr[i]-arr[i-1])),(dp[i-2]+abs(arr[i]-arr[i-2])));
    }
    return dp[n-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n),dp(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int res = solve(arr,dp,n);
    cout<<res<<endl;
    return 0;
}