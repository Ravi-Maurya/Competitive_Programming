class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        int invert = n-2;
        while(invert>=0 && nums[invert]>=nums[invert+1])
            invert--;
        if(invert==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(i = n-1; i>=invert+1; i--){
            if(nums[invert] < nums[i]){
                swap(nums[invert],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+(invert+1), nums.end());
        return;
    }
};