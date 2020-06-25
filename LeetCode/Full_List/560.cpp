class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr = 0, res = 0;
        unordered_map<int,int> ump;
        ump[0] = 1;
        for(int i=0; i<nums.size(); i++){
            curr += nums[i];
            if(ump.count(curr-k))
                res += ump[curr-k];
            ump[curr]++;
        }
        return res;
    }
};