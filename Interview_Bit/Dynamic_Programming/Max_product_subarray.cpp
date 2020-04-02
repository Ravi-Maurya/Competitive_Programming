int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    int maxsofar = A[0];
    int currmax = A[0];
    int currmin = A[0];
    for(int i=1;i<n;i++){
        if (A[i]<0)
            swap(currmax,currmin);
        currmax = max(A[i],currmax*A[i]);
        currmin = min(A[i],currmin*A[i]);
        maxsofar = max(maxsofar,currmax);
    }
    return maxsofar;
}
