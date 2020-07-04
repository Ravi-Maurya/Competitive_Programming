#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& house, int n){
    if(n==0)
        return 0;
    if(n==1)
        return house[0];
    if(n==2)
        return max(house[0],house[1]);
    int dp[n+1];
    dp[0] = 0;
    dp[1] = house[0];
    dp[2] = max(house[0],house[1]);
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + house[i-1]);
    }
    return dp[n];
}

int main(){
    return 0;
}