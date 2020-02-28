#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSubArray(const vector<int> &A) {
    int n = A.size();
    int max_so_far = A[0];
    int curr_sum = A[0];
    for(int i=1;i<n;i++){
        curr_sum = max(A[i],A[i]+curr_sum);
        max_so_far = max(max_so_far,curr_sum);
    }
    return max_so_far;
}
};