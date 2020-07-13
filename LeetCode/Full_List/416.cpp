class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& x: nums)
            sum += x;
        if(sum&1)
            return false;
        sum >>= 1;
        int n = nums.size();
        bool dp[n+1][sum+1];
        memset(dp,false,sizeof(dp));
        for(int i=0; i<=n; i++)
            dp[i][0] = true;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};