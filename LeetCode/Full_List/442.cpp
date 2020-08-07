class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            int curr_idx = abs(nums[i])-1;
            if(nums[curr_idx]<0)
                res.push_back(abs(nums[i]));
            else
                nums[curr_idx] *= -1;
        }
        return res;
    }
};