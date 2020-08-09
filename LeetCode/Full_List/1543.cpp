class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> ust;
        ust.insert(0);
        int curr=0, res=0;
        for(int x : nums) {
            curr+=x;
            if(ust.count(curr-target)) {
                ++res;
                ust.clear();
            }
            ust.insert(curr);
        }
        return res;
    }
};