#include<bits/stdc++.h>
using namespace std;

int lps(vector<int>& arr, int n){
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++)
        dp[i][i] = 1;
    for(int i=0; i<n-1; i++)
        dp[i][i+1] = (arr[i]==arr[i+1])?2:0;
    for(int length=3; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            if(arr[i] == arr[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}

int solve(vector<int>& arr, int n){// arr1 -> lps as lps is closest longest palindrome sequence and add the missing numbers
    return n - lps(arr,n);
}

int main(){
    return 0;
}