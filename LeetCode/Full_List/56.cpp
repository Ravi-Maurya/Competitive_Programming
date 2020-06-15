class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int i = 0;
        res.push_back(intervals[i]);
        int j = 1;
        int n = intervals.size();
        while(j<n){
            if(res[i][1]>= intervals[j][0]){
                res[i][0] = min(intervals[j][0],res[i][0]);
                res[i][1] = max(intervals[j][1],res[i][1]);
            }
            else{
                res.push_back(intervals[j]);
                i++;
            }
            j++;
        }
        return res;
    }
};