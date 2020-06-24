class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        if(n==0)
            return 0;
        int res = nums[0];
        int curr_max = res;
        int curr_min = res;
        for(int i=1; i<n; i++){
            if(nums[i]<0)
                swap(curr_max,curr_min);
            curr_max = max(curr_max*nums[i],nums[i]);
            curr_min = min(curr_min*nums[i],nums[i]);
            res = max(res,curr_max);
        }
        return res;
    }
};