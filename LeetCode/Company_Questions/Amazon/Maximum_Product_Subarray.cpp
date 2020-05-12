class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int max_so_far = nums[0];
        int curr_max = nums[0];
        int curr_min = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]<0)
                swap(curr_max, curr_min);
            curr_max = max(nums[i], curr_max*nums[i]);
            curr_min = min(nums[i],curr_min*nums[i]);
            max_so_far = max(max_so_far,curr_max);
        }
        return max_so_far;
    }
};