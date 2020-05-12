#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n){
    if(i<0 || i>=n || j<0 || j>=n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;
    if(j<n-1 &&(matrix[i][j]+1)==matrix[i][j+1])
        x = 1 + helper(i,j+1,matrix,dp,n);
    if(j>0 &&(matrix[i][j]+1)==matrix[i][j-1])
        x = 1 + helper(i,j-1,matrix,dp,n);
    if(i>0 &&(matrix[i][j]+1)==matrix[i-1][j])
        x = 1 + helper(i-1,j,matrix,dp,n);
    if(i<n-1 &&(matrix[i][j]+1)==matrix[i+1][j])
        x = 1 + helper(i+1,j,matrix,dp,n);
    
    dp[i][j] = max({x,y,z,w,1});
    return dp[i][j];
}

int find_longest_Path(vector<vector<int>>& matrix){
    //Longest path in matrix from any point to any point with increasing of differnce of 1
    int n = matrix.size();
    vector<vector<int>> dp(n,vector<int>(dp,-1));
    int res = 1;
    for(int i=0; i<n;i++)
        for(int j=0; j<n; j++){
            if(dp[i][j]==-1)
                helper(i,j,matrix,dp,n);
            res = max(res,dp[i][j]);
        }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}