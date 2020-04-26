class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> ust,ust2;
        for(auto x: nums1){
            if(ust.find(x)==ust.end())
                ust.insert(x);
        }
        for(auto x: nums2){
            if(ust.find(x)!=ust.end())
                if(ust2.find(x)==ust2.end())
                    ust2.insert(x);
        }
        for(auto x: ust2)
            res.push_back(x);
        return res;
    }
};