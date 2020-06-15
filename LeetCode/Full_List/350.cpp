class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mst1,mst2;
        for(auto& x:nums1)
            mst1[x]++;
        for(auto& x:nums2)
            mst2[x]++;
        vector<int> res;
        for(auto& [x,val]:mst1){
            int count = val;
            if(mst2.count(x)){
                count = min(count,mst2[x]);
                while(count--){
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};