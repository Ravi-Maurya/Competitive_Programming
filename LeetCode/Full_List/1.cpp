class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n; i++){
            int diff = target-nums[i];
            if(ump.count(diff))
                return {ump[diff],i};
            ump[nums[i]] = i;
        }
        return {};
    }
};