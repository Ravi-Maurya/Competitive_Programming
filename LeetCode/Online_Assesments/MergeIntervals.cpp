#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
    static bool compare(vector<int> x, vector<int> y){
        return (x[0] < y[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int n = intervals.size(),i,j;
        if (n<=1)
            return intervals;
        vector <vector<int>> res;
        i =0, j = 1;
        res.push_back(intervals[0]);
        while(j<n){
            if(res[i][1]>=intervals[j][0]){
                res[i][0] = min(res[i][0], intervals[j][0]);
                res[i][1] = max(res[i][1], intervals[j][1]);
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
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}