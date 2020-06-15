class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i = 0, j = 0, n = nums.size();
        int res = INT_MAX;
        int sum = 0;
        while(j<n){
            while(sum<s && j<n){
                sum += nums[j];
                j++;
            }
            while(sum>=s && i<j){
                res = min(res,j-i);
                sum -= nums[i++];
            }
        }
        return (res==INT_MAX?0:res);
    }
};