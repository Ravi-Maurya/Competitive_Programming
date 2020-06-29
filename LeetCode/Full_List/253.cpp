class Solution {
    /*
    Idea is to check if any room currently can be freed that was preoccupied
    */
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0)
            return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minheap;
        minheap.push(intervals[0][1]);
        for(int i =1; i<n; i++){
            if(minheap.top()<=intervals[i][0]){
                minheap.pop();
            }
            minheap.push(intervals[i][1]);
        }
        return minheap.size();
    }
};


class Solution {//given best Solution still need to understand
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<2)
            return n;
        vector<int> start(n),end(n);
        for(int i=0; i<n; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i = 0, j =0;
        int res = 0;
        while(i<n){
            if(start[i]>=end[j]){
                res--;
                j++;
            }
            res++;
            i++;
        }
        return res;
    }
};