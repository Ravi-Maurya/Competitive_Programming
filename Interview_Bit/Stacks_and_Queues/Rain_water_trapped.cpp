int Solution::trap(const vector<int> &A) {
    int n = A.size();
    if(n==0)
        return 0;
    vector<int> left(n), right(n);
    left[0] = A[0];
    right[n-1] = A[n-1];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],A[i]);
        right[n-i-1] = max(right[n-i],A[n-i-1]);
    }
    int res=0;
    for(int i=0;i<n;i++)
        res += min(left[i],right[i])-A[i];
    return res;
}
