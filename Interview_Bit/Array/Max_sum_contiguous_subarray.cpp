int Solution::maxSubArray(const vector<int> &A) {
    int global_max = A[0];
    int curr_max = A[0];
    int n = A.size(),i;
    for(i=1;i<n;i++){
        curr_max = max(A[i],curr_max+A[i]);
        global_max = max(curr_max,global_max);
    }
    return global_max;
}