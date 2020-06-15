class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ust2,ust1;
        for(auto x: nums1)
            ust1.insert(x);
        for(auto x: nums2)
            ust2.insert(x);
        vector<int> res;
        for(auto& x:ust1){
            if(ust2.count(x))
                res.push_back(x);
        }
        return res;
    }
};