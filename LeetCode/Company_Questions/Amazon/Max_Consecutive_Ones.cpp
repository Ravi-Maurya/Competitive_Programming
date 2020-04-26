class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int i =0, n = nums.size();
        while(i<n){
            int count =0;
            while(i<n && nums[i]==1)
                i++,count++;
            res = max(count,res);
            while(i<n && nums[i]==0)
                i++;
        }
        return res;
    }
};