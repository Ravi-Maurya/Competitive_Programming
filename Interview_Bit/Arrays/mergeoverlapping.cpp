/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a, Interval b){
    return a.start<b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    sort(A.begin(),A.end(),comp);
    int idx = 0;
    for(int i=1;i<n;i++){
        if (A[idx].end>=A[i].start){
            A[idx].end = max(A[idx].end,A[i].end);
            A[idx].start = min(A[idx].start,A[i].start);
        }
        else{
            idx++;
            A[idx] = A[i];
        }
    }
    vector<Interval> res;
    for(int i=0;i<=idx;i++)
        res.emplace_back(A[i]);
    return res;
}
