#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
int find_minimum(vector<int> arr){//Divide arr in two subsets such that abs difference is minimum
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int j=1; j<=sum; j++)
        dp[0][j] = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1])
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
    int res = INT_MAX;
    for(int j=sum/2; j>=0; j--)
        if(dp[n][j]){
            res = sum - 2*j;
            break;
        }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}