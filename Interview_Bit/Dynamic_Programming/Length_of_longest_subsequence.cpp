int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if(n==0)
        return 0;
    vector<int> LIS(n,1), LDS(n,1);
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(A[i]>A[j] && LIS[i]<LIS[j]+1)
                LIS[i] = LIS[j]+1;
    
    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>i;j--)
            if(A[i]>A[j] && LDS[i]<LDS[j]+1)
                LDS[i] = LDS[j]+1;
    int res = LIS[0] + LDS[0] - 1;
    for(int i=1;i<n;i++)
        res = max(res,LIS[i] + LDS[i] - 1);
    return res;
}
