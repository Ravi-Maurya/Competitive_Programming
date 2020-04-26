class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for(auto x: nums){
            if(check.find(x)!=check.end())
                return true;
            check.insert(x);
        }
        return false;
    }
};