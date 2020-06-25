class Solution{
    public:
    int twoSumLessThanK(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        int i = 0, j =nums.size()-1;
        int res = -1;
        while(i<j){
            if(nums[i]+nums[j]>=k)
                j--;
            else{
                res = max(res,nums[i]+nums[j]);
                i++;
            }
        }
        return res;
    }
}