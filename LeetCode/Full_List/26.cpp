class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i = 0;
        int n = nums.size();
        int j = 0;
        while(j<n){
            while(j<n && nums[i]==nums[j])
                j++;
            if(j<n){
                i++;
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return i+1;
    }
};