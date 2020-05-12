#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// Recursive - 
// edit(i,j) = edit(i-1,j-1), if(a[i]==b[j])
//             1 + min(edit(i-1,j-1),edit(i-1,j),edit(i,j-1))
int edit_dist(string a, string b){
    int m = s.size(), n = b.size();
    int dp[2][n+1];
    memset(dp,0, sizeof(dp));
    for(int j=0;j<=n;j++)
        dp[0][j] = j;
    bool bi;
    for(int i=1;i<=m;i++){
        bi = i&1;
        for(int j=0;j<=n;j++){
            if(j==0)
                dp[bi][j] = i;
            else if(a[i-1]==b[j-1])
                dp[bi][j] = dp[1-bi][j-1];
            else
                dp[bi][j] = 1 + min({dp[1-bi][j-1],dp[1-bi][j],dp[bi][j-1]});
        }
    }
    return dp[bi][n];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}