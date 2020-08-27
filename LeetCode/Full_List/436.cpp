class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> mp;
        int n = intervals.size();
        vector<int> res(n,-1);
        for(int i=0; i<n; i++)
            mp[intervals[i][0]] = i;
        for(int i=0; i<n; i++){
            auto it = mp.lower_bound(intervals[i][1]);
            if(it!=mp.end())
                res[i] = it->second;
        }
        return res;
    }
};