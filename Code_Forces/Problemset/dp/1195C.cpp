#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
unsigned long long int recursive(vector<vector<int>>& arr, int n, int i, int bi, vector<vector<unsigned long long int>>& dp){
    if(i>=n)
        return 0;
    if(dp[i][bi]!=-1)
        return dp[i][bi];
    if(bi==2){
        dp[i][bi] = max({arr[0][i] + recursive(arr,n,i+1,1,dp),
        arr[1][i] + recursive(arr,n,i+1,0,dp),
        recursive(arr,n,i+1,2,dp)});
    }
    else if(bi==0){
        dp[i][bi] = max({
            arr[0][i] + recursive(arr,n,i+1,1,dp),
            recursive(arr,n,i+1,2,dp)
        });
    }
    else{
        dp[i][bi] = max({
            arr[1][i] + recursive(arr,n,i+1,0,dp),
            recursive(arr,n,i+1,2,dp)
        });
    }
    return dp[i][bi];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> arr(2,vector<int>(n));
    vector<vector<unsigned long long int>> dp(n,vector<unsigned long long int>(3,-1));
    for(int i=0;i<n;i++)
        cin>>arr[0][i];
    for(int i=0;i<n;i++)
        cin>>arr[1][i];
    cout<<recursive(arr,n,0,2,dp)<<"\n";
    return 0;
}