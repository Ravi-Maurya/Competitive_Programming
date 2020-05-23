class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int length = 0;
        for(auto num: nums){
            int i = lower_bound(dp.begin(),dp.begin()+length,num) - dp.begin();
            dp[i] = num;
            if(i==length)
                length++;
            
        }
        return length;
    }
};