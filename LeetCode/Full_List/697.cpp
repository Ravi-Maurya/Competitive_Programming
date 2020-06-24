class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,pair<int,int>> ump;
        int degree = 0;
        int val = -1, li = n+1, ri = -1;
        for(int i=0; i<n; i++){
            if(!ump.count(nums[i]))
                ump[nums[i]] = {0,i};
            ump[nums[i]].first += 1;
            if(ump[nums[i]].first>degree || (ump[nums[i]].first==degree && ri-li+1>i-ump[nums[i]].second+1)){
                degree = ump[nums[i]].first;
                val = nums[i];
                li = ump[nums[i]].second;
                ri = i;
            }
        }
        return ri-li+1;
    }
};