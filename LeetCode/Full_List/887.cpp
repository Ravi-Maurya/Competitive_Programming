class Solution {
public:
    int superEggDrop(int k, int n){//O(n2)
        if(k==0 || n==0)
            return 0;
        int dp[10001][101]={0};
        for(int i=1;i<=k;i++)
            dp[1][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j] = 1 + dp[i-1][j-1] + dp[i-1][j];
                if(dp[i][j]>=n)
                    return i;
            }
        }
        return 1;
    }
};

class Solution {
public:
    int superEggDrop(int e, int f) {//O(n3)
        int dp[e+1][f+1];
        for(int i=1; i<=e;i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int j=1; j<=f; j++)
            dp[1][j] = j;
        for(int egg=2; egg<=e; egg++){
            for(int fl = 2; fl<=f; fl++){
                dp[egg][fl] = INT_MAX;
                for(int k=1; k<=fl; k++){
                    int tmp = 1 + max(dp[egg-1][k-1],dp[egg][fl-k]);
                    dp[egg][fl] = min(dp[egg][fl],tmp);
                }
            }
        }
        return dp[e][f];
    }
};