#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n<=2)
        return n;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int solve(int n, int m){// Generalized for m stairs at a time O(n*m)
    int res[n];
    res[0] = 0;
    res[1] = 1;
    for(int i=2; i<n; i++){
        res[i] = 0;
        for(int j=1; j<=m && j<=i; j++)
            res[i] += res[i-j];
    }
    return res[n-1];
}

int optSolve(int n, int m){// SLiding Window
    int dp[n+1];
    int tmp = 0;
    res[0] = 1;
    for(int i=1; i<=n; i++){
        int s = i-m-1;
        int e = i-1;
        if(s>=0)
            tmp -= dp[s];
        tmp += dp[e];
        dp[i] = tmp;
    }
    return res[n];
}

int main(){
    return 0;
}