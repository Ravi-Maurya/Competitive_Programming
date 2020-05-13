#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int lps(string s){
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int res = 1;
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
        if(i<n-1){
            dp[i][i+1] = s[i]==s[i+1]?2:0;
            res = max(res,dp[i][j]);
        }
    }
    for(int length = 3; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            if(s[i]==s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
                res = length;
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return res;
}

int lpsubstring(string s){
    int n = s.size();
    vector<vector<bool>> dp(n,vector<bool>(n,0));
    int res = 1;
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
        if(i<n-1){
            dp[i][i+1] = s[i]==s[i+1]?1:0;
            if(dp[i][i+1])
                res = 2;
        }
    }
    for(int length = 3; length<=n; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
            if(dp[i][j])
                res = length;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}