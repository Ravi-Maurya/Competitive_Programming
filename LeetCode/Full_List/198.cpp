class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        if(n<=2)
            return *max_element(nums.begin(),nums.end());
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=3;i<=n;i++){
            dp[i-1] = max(nums[i-1]+dp[i-3], dp[i-2]);
        }
        return dp[n-1];
    }
};