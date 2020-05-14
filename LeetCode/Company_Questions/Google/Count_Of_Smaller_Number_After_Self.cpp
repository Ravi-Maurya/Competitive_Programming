class Solution {
    public:
    vector<int> countSmaller(vector<int>& nums) {
        vector< pair<int, int>> arr;
        vector<int> count(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        merge_with_inversions(0, nums.size(), arr, count);
        return count;
    }
    void merge_with_inversions(int start, int end, vector<pair<int, int>> &arr, vector<int>& count) {
        if(start < end && end - start > 1) {
            int mid = start + (end - start) / 2;
            merge_with_inversions(start, mid, arr, count);
            merge_with_inversions(mid, end, arr, count);
            vector< pair<int, int>> ans;
            int i = start, j = mid;
            int inversions = 0;
            while(i < mid && j < end) {
                if(arr[i].first <= arr[j].first) {
                    ans.push_back(arr[i]);
                    count[arr[i].second] += inversions;
                    i++;
                }
                else {
                    ans.push_back(arr[j]);
                    inversions++;
                    j++;
                }
            }

            while(i < mid) {
                ans.push_back(arr[i]);
                count[arr[i].second] += inversions;
                i++;
            }

            while(j < end) {
                ans.push_back(arr[j]);
                j++;
            }
            j=0;
            for(int i=start; i<end; i++) {
                arr[i] = ans[j];
                j++;
            }           
        }
    }
};