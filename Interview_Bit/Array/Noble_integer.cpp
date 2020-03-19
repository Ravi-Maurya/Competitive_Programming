int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size(),i;
    for(i=0;i<n;i++)
        if (A[i]==(n-i-1) && (i+1>=n || A[i]!=A[i+1]))
            return 1;
    return -1;
}
