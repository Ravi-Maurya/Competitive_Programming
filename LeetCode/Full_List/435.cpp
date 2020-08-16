class Solution {
public:
    
    static bool compare(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<2)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        auto prev = intervals[0];
        int res = 0;
        for(int i=1; i<n; i++){
            if(prev[1]>intervals[i][0])
                res++;
            else
                prev = intervals[i];
        }
        return res;
    }
};