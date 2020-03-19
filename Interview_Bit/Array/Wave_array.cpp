vector<int> Solution::wave(vector<int> &A) {
    int n = A.size(),i;
    sort(A.begin(),A.end());
    for(i=0;i<n;i+=2)
        if (i+1<n)
            swap(A[i],A[i+1]);
    return A;
}
