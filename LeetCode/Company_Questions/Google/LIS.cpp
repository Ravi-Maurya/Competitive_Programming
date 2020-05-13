class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int res = 1;
        vector<int> lis(n,1);
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                if(nums[j]<nums[i] && lis[i]<lis[j]+1){
                    lis[i] = lis[j] + 1;
                    if(res<lis[i])
                        res = lis[i];
                }
        
        return res;
    }
};