class Solution {
public:
    int dp[25][2005];
    Solution(){
        for(int i=0; i<25; i++)
            for(int j=0; j<2005;j++)
                dp[i][j] = INT_MIN;
    }
    int solve(vector<int>& nums, int i, int sum, int S){
        if(i==nums.size()){
            if(sum == S)
                return 1;
            else
                return 0;
        }
        if(dp[i][sum + 1000]!=INT_MIN){
            return dp[i][sum + 1000];
        }
        int add = solve(nums,i+1,sum+nums[i],S);
        int sub = solve(nums,i+1,sum-nums[i],S);
        dp[i][sum+1000] = add + sub;
        return dp[i][sum+1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return solve(nums,0,0,S);
    }
};