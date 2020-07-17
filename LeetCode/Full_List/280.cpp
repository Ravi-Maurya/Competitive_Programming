class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return;
        for(int i=1; i<n; i++){
            if(i%2 == 1){
                if(nums[i-1]>nums[i])
                    swap(nums[i],nums[i-1]);
            }
            else{
                if(nums[i-1]<nums[i])
                    swap(nums[i],nums[i-1]);
            }
        }
        return;
    }
};