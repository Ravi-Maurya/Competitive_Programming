class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<2)
            return true;
        sort(intervals.begin(),intervals.end());
        bool flag = true;
        for(int i=0; i<n-1; i++){
            if(intervals[i][1]>intervals[i+1][0]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};