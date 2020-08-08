class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int res = 0;
        int count = 0;
        int n = nums.size();
        while(i<n){
            while(i<n && nums[i]==1){
                count++;
                i++;
            }
            if(count>res)
                res = count;
            count = 0;
            i++;
        }
        return res;
    }
};