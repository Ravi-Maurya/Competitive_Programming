class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int l = 0, h = n-1;
        while(l<h){
            int mid = l + (h - l)/2;
            if(nums[mid]<nums[h])
                h = mid;
            else if(nums[mid]>nums[h])
                l = mid+1;
            else
                h -= 1;
        }
        return nums[l];
    }
};