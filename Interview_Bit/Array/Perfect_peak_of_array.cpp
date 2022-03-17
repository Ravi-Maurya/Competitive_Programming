int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    vector<bool> leftmax(n, false), rightmin(n, false);
    int mx = A[0], mn = A[n-1];
    for(int i=1; i<n; i++){
        if(A[i] > mx){
            mx = A[i];
            leftmax[i] = true;
        }
        if (A[n-i-1] < mn){
            mn = A[n-i-1];
            rightmin[n-i-1] = true;
        }
    }
    for(int i=1; i<n; i++){
        if(leftmax[i] && rightmin[i])
            return 1;
    }
    return 0;
}
