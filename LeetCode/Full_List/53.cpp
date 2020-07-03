class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int curr = nums[0], res = nums[0];
        for(int i=1; i<n; i++){
            curr = max(curr+nums[i],nums[i]);
            if(res<curr)
                res = curr;
        }
        return res;
    }
};