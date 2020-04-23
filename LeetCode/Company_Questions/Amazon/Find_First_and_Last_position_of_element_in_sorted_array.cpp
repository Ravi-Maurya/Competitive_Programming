class Solution {
public:
    int lowerBsearch(vector<int>& nums, int target){
        int l =0, r = nums.size();
        while(l<r){
            int mid = (l+r)>>1;
            if(nums[mid]==target){
                if(mid==0 || nums[mid-1]<target)
                    return mid;
                else
                    r--;
            }
            else if(nums[mid]>target)
                r--;
            else
                l++;
        }
        return -1;
    }
    
    int upperBsearch(vector<int>& nums, int target){
        int l =0, r = nums.size();
        while(l<r){
            int mid = (l+r)>>1;
            if(nums[mid]==target){
                if(mid==nums.size()-1 || nums[mid+1]>target)
                    return mid;
                else
                    l++;
            }
            else if(nums[mid]>target)
                r--;
            else
                l++;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(lowerBsearch(nums,target));
        res.push_back(upperBsearch(nums,target));
        return res;
    }
};