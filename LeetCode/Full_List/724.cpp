class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0, left = 0;
        for(int x: nums)
            s += x;
        for(int i=0; i<nums.size(); i++){
            if(left == s - left - nums[i])
                return i;
            left += nums[i];
        }
        return -1;
    }
};