class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int i = 0, j = 0;
        int curr = 0;
        int res = n+1;
        while(j<n){
            curr += nums[j];
            while(curr>=s){
                res = min(res,j+1-i);
                curr -= nums[i++];
            }
            j++;
        }
        return res==n+1 ? 0 : res;
    }
};