#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// If one person can attend all meetings
class Solution{
    public:
    bool canMeetings(Interva[] intervals){
        int n = intervals.size();
        vector<int> starting(n), ending(n);
        for(int i=0; i<n; i++){
            starting[i] = intervals[i].start;
            ending[i] = intervals[i].end;
        }
        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());
        for(int i=0; i<n-1; i++)
            if(starting[i+1]<ending[i])
                return false;
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}