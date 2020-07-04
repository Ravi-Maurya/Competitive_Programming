#include<bits/stdc++.h>
using namespace std;

int rec(int n){
    if(n<=1)
        return 0;
    int res = 0;
    for(int i=1; i<n; i++)
        res = max({res, i *(n-i), i*rec(n-i)});
    return res;
}

int solve(int n){
    if(n<=1)
        return 0;
    int dp[n+1];
    dp[0] = dp[1] = 0;
    for(int i=1; i<=n; i++){
        int res = 0;
        for(int j=1; j<=i/2; j++){
            res = max({res,(i-j)*j, j*dp[i-j]});
        }
        dp[i] = res;
    }
    return dp[n];
}

int main(){
    return 0;
}