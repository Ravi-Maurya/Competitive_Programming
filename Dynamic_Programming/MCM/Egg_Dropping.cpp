#include<bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

int eggs(int e, int f){
    if(f==0 || f==1 || e==1)
        return f;
    int res = INT_MAX;
    for(int k=1; k<=f; k++){
        int s1 = eggs(e-1,k-1);
        int s2 = eggs(e,f-k);
        int tmp = 1 + max(s1,s2);//worst case scene
        res = min(res,tmp);// best solution
    }
    return res;
}
int solve(int e, int f){
    int dp[e+1][f+1];
    for(int i=1; i<=e; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int j=1; j<=f; j++)
        dp[1][j] = j;
    for(int egg = 2; egg<=e;egg++){
        for(int flr = 2; flr<=f; flr++){
            dp[egg][flr] = INT_MAX;
            for(int k=1;k<=flr; k++){
                int tmp = 1 + max(dp[egg-1][k-1],dp[egg][flr-k]);
                dp[egg][flr] = min(dp[egg][flr],tmp);
            }
        }
    }
    return dp[e][f];
}
