#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n){
    bool dp[n][n];
    memset(dp,false,sizeof(dp));
    for(int i=0; i<n; i++)
        dp[i][i] = true;
    int max_length = 1, idx = 0;
    for(int i=0; i<n-1; i++){
        dp[i][i+1] = arr[i]==arr[i+1];
        if(dp[i][i+1] && 2>max_length){
            max_length = 2;
            idx = i;
        }
    }
    for(int length = 3; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            if(arr[i] == arr[j])
                dp[i][j] = dp[i+1][j-1];
            else
                dp[i][j] = false;
            
            if(dp[i][j] && length>max_length){
                max_length = length;
                idx = i;
            }
        }
    }
    return max_length;
}

int main(){
    return 0;
}