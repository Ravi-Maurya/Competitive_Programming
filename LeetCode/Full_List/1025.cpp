class Solution {
public:
    bool divisorGame(int N) {
        return N%2==0;
    }
};

class Solution {
public:
    bool divisorGame(int N) {
        if(N==1)
            return false;
        bool dp[N+1];
        memset(dp,false,sizeof(dp));
        dp[1] = false;
        dp[2] = true;
        for(int i=3; i<=N; i++){
            for(int j=1; j<i; j++){
                if(i%j==0 && !dp[i-j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};