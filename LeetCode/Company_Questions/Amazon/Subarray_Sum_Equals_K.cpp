class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for(int i=0; i<n; i++){
            int curr_sum = 0;
            for(int j = i; j<n; j++){
                curr_sum += nums[j];
                if(curr_sum==k)
                    res++;
            }
        }
        return res;
    }
};