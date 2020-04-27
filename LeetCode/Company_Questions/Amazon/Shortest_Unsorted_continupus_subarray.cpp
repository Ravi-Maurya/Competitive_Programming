class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        bool flag = false;
        for(int i=1; i< nums.size(); i++){
            if(nums[i]<nums[i-1])
                flag = true;
            if(flag)
                mn = min(mn,nums[i]);
        }
        flag = false;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]>nums[i+1])
                flag = true;
            if(flag)
                mx = max(mx,nums[i]);
        }
        int l,r;
        l = 0;
        while(l<nums.size() && mn>=nums[l])
            l++;
        r = nums.size()-1;
        while(r>=0 && mx<=nums[r])
            r--;
        return r-l<0?0:r-l+1;
    }
};