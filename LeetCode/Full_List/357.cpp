class Solution {
public:
    int dp[10];
    Solution(){
        dp[0] = 0;
        dp[1] = 10;
        dp[2] = 9*9;
        for(int i=3; i<=9;i++){
            dp[i] = dp[i-1]*(9-i+2);
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        long long int res = 0;
        for(int i=0; i<=n; i++)
            res += dp[i];
        return res;
    }
};