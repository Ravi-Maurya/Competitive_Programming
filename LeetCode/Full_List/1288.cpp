class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int res = 0;
        int curr,prev = 0;
        for(auto interval: intervals){
            curr = interval[1];
            if(prev<curr){
                ++res;
                prev = curr;
            }
        }
        return res;
    }
};