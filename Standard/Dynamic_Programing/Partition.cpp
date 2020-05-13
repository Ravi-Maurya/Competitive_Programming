#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
bool partition(vector<int> arr){
    int n = arr.size();
    int sum = 0;
    for(auto& x:arr)
        sum += x;
    if(sum&1)
        return false;
    vector<vector<bool>> dp(n+1, vector<bool>((sum>>1)+1,false));
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(sum>>1); j++){
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1])
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][(sum>>1)];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}