#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// https://codeforces.com/problemset/problem/414/B

const int mod = 1e9 + 7;
int solve(int n, int k){
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    for(int j=1;j<=n;j++)
        dp[1][j] = 1;
    for(int l = 1; l<k ; l++){
        for(int x = 1; x<=n; x++){
            for(int i = 1; i*x<=n; i++){
                dp[l+1][i*x] += dp[l][x];
                dp[l+1][i*x] -= dp[l+1][i*x]/mod*mod;
            }
        }
    }
    int res = 0;
    for(int x=1; x<=n; x++){
        res += dp[k][x];
        res -= res/mod*mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<"\n";
    return 0;
}