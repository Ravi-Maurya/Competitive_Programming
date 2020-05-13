#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int recursive(vector<int> arr, int i, int j){
    if(i==j)
        return 0;
    int mn = INT_MAX;
    int count;
    for(int k=i;k<j;k++){
        count = recursive(arr,i,k) + recursive(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(count<mn)
            mn = count;
    }
    return mn;
}

int mcm(vector<int>arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int length = 2; length<=n; lenght++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int tmp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(tmp<dp[i][j])
                    dp[i][j] = tmp;
            }
        }
    }
    ret dp[1][n-1];// 1 <-> n-1 as there are only n-1 matrices and not n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}