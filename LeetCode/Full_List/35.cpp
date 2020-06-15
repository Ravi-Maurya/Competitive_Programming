class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=target)
                low = mid+1;
            else
                high = mid;
        }
        if(low-1>=0 && nums[low-1]==target)
            return low-1;
        return low;
    }
};
