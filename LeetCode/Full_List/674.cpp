class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1, res = 1, n = nums.size();
        if(n==0)
            return 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1])
                count++;
            else{
                res = max(res,count);
                count = 1;
            }
        }
        return max(res,count);
    }
};