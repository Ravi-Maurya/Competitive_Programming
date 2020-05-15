class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums2.empty() || nums1.empty()) return {};
        priority_queue<pair<int, vector<int>>> maxheap;
        vector<vector<int>> result;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(maxheap.size() < k)
                    maxheap.push({nums1[i]+nums2[j], vector<int>({nums1[i],nums2[j]})});
                else if(maxheap.size() == k && maxheap.top().first > nums1[i]+nums2[j]) {
                    maxheap.pop();
                    maxheap.push({nums1[i]+nums2[j], vector<int>({nums1[i],nums2[j]})});
                }
           }
        }
        while(!maxheap.empty()) {
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return result;
    }
};