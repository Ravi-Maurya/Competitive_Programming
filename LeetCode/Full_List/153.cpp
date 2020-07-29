class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(nums[0]<nums[n-1])
            return nums[0];
        int i=0, j = n-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]>nums[j])
                i = mid+1;
            else if(nums[mid]<nums[j])
                j = mid;
            else
                return nums[mid];
            
        }
        return -1;
    }
};