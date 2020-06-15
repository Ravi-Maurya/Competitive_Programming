class Solution {
public:
    int bsearchindex(vector<int>& nums, int target, bool left, int l ,int h){
        while(l<h){
            int mid = (l+h)/2;
            if(nums[mid]>target || (left && target==nums[mid]))
                h = mid;
            else
                l = mid+1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        if(nums.empty())
            return res;
        int n = nums.size();
        int idx = bsearchindex(nums,target,true,0,n);
        if(idx==n || nums[idx]!=target)
            return res;
        res[0] = res[1] = idx;
        idx = bsearchindex(nums,target,false,res[0],n);
        res[1] = idx-1;
        return res;
    }
};