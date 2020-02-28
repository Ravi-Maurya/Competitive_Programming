#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int i=0;i<n;i++){
        max1 = max(max1,A[i]+i);
        max2 = max(max2,A[i]-i);
        min1 = min(min1,A[i]+i);
        min2 = min(min2,A[i]-i);
    }
    int ans = max(abs(max2-min2),abs(max1-min1));
    return ans;
}
};