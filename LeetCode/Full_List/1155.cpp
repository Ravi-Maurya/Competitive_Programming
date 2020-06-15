class Solution {
public:
    const int mod = 1000000007;
    int dp[31][31][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int numRollsToTarget(int d, int f, int target) {
        if(d==0){
            if(target!=0)
                return 0;
            return 1;
        }
        if(d==1){
            if(target==0)
                return 0;
            if(target<=f)
                return 1;
            return 0;
        }
        if(dp[d][f][target]!=-1)
            return dp[d][f][target];
        int res = 0;
        for(int i = 1; i<=f; i++){
            if(target-i<0)
                break;
            res =  (res%mod + numRollsToTarget(d-1,f,target-i)%mod)%mod;
        }
        dp[d][f][target] = res%mod;
        return dp[d][f][target];
    }
};

class Solution {
public:
    const int mod = 1000000007;
    int numRollsToTarget(int d, int f, int target) {
        if(target>d*f)
            return 0;
        if(target<d)
            return 0;
        long int dp[d+1][target+1];
        for(int i=0;i<=d;i++)
            dp[i][0]=0;
        for(int i=0;i<=target;i++)
            dp[0][i]=0;
        dp[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int j=1;j<=target;j++){
                dp[i][j]=0;
                for(int k=1;k<=f;k++){
                    if(k>j)
                        break;
                    dp[i][j] = (dp[i][j]%mod + dp[i-1][j-k]%mod)%mod;
                }
            }
        }
        return dp[d][target];
    }
};