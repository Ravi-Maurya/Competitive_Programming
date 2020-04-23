#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// number of meeting rooms required.
class Solution{
    public:
    static bool compare(Interval& a, Interval& b){
        if(a.start == b.start)
            return a.end<=b.end;
        return a.start<=b.start;
    }
    int solve(vector<Interval>& intervals){
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        struct comp{
            bool operator()(const Interval& a, const Interval& b){
                if(a.start == b.start)
                    return a.end<=b.end;
                return a.start<=b.start;
            }
        };
        priority_queue<Interval, vector<Interval>, comp> pq;
        pq.push(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            auto curr = intervals[i];
            auto earliest = pq.top();
            pq.pop();
            if(curr.start >= earliest.end)
                earliest.end = curr.end;
            else
                pq.push(curr);
            pq.push(earliest);
        }
        return pq.size();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}