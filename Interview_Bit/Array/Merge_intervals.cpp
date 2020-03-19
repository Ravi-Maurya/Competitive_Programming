/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval x, Interval y){
    return (x.start < y.start);
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end(),compare);
    int n = intervals.size(),i,j;
    if (n==1)
        return intervals;
    vector <Interval> res;
    i = 0;
    j = 1;
    res.push_back(intervals[0]);
    while (j<n){
        if (res[i].end>=intervals[j].start){
            res[i].start = min(res[i].start,intervals[j].start);
            res[i].end = max(res[i].end,intervals[j].end);
            j++;
        }
        else{
            res.push_back(intervals[j]);
            i++;
            j++;
        }
    }
    return res;
}
