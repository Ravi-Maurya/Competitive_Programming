#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n){
    bool dp[n][n];
    memset(dp,false,sizeof(dp));
    int count[n][n];
    memset(count,0,sizeof(count));
    for(int i=0; i<n; i++){
        dp[i][i] = true;
        count[i][i] = 1;// considering the single charachter as palindrome is not put 0
    }
    for(int i=0; i<n-1; i++){
        if(arr[i] == arr[i+1]){
            dp[i][i+1] = true;
            count[i][i+1] = count[i][i] + count[i+1][i+1] - count[i+1][i] + 1;
        }
        
    }
    for(int length = 3; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            if(arr[i] == arr[j])
                dp[i][j] = dp[i+1][j-1];
            else
                dp[i][j] = false;
            
            if(dp[i][j])
                count[i][j] = count[i+1][j] + count[i][j-1] + 1 - count[i+1][j-1];
            else
                count[i][j] = count[i+1][j] + count[i][j-1] - count[i+1][j-1];
        }
    }
    return count[0][n-1];
}

int main(){
    return 0;
}