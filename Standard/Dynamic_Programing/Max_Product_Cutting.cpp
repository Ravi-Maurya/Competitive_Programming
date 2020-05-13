#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int recursive(int n){
    if(n<=1)
        return 0;
    int mx = 0;
    for(int i=1; i<n; i++)
        mx = max({mx,i*(n-i), i*recursive(n-i)});
    return mx;
}

int maxProd1(int n){
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        int mx = 0;
        for(int j=1; j<=i/2; j++)
            mx = max({mx,(i-j)*j, dp[i-j]*j})
        dp[i] = mx;
    }
    return dp[n];
}

int maxProd2(int n){
    if(n==0)
        return 0;
    if(n<=3)
        return n-1;
    int res = 1;
    while(n>4){
        n -= 3;
        res*=3;
    }
    return n*res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}