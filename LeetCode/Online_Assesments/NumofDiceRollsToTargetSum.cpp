#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
    int numRollsToTarget(int d, int f, int target){
        int dp[d+1][target+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=d;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=target;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=f;i++){
            if(i<=target)
                dp[1][i]=1;
        }
        for(int i=2;i<=d;i++)
            for(int j=0;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(j>k)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-k])%(1000000000+7);
                }
            }
        return dp[d][target];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}