#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1)
        return n;
    return fib(n-1) + fib(n-2);
}

int solve(int n){
    if(n<=1)
        return n;
    int dp[n+1];
    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main(){
    return 0;
}