#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int solve(vector<int>& arr, vector<int>& dp, int n, int k){
    dp[0] = 0;
    if(n==1)
        return dp[0];
    for(int i=1; i<n; i++){
        int x = 1;
        while(i-x>=0 && x<=k){
            dp[i] = min(dp[i],(dp[i-x]+abs(arr[i-x]-arr[i])));
            x++;
        }
    }
    return dp[n-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n),dp(n,INT_MAX);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int res = solve(arr,dp,n,k);
    cout<<res<<endl;
    return 0;
}