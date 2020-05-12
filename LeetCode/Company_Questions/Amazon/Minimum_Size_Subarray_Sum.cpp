class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int curr_sum = 0;
        int n = nums.size();
        int left = 0;
        int res= INT_MAX;
        for(int i=0; i<n; i++){
            curr_sum += nums[i];
            while(curr_sum >= s){
                res = min(res,i+1-left);
                curr_sum -= nums[left++];
            }
        }
        return res!=INT_MAX?res:0;
    }
};