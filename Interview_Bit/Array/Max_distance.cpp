int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> leftmin(n,0), rightmax(n,0);
    leftmin[0] = A[0];
    rightmax[n-1] = A[n-1];
    for(int i=1;i<n;i++){
        leftmin[i] = min(leftmin[i-1],A[i]);
        rightmax[n-i-1] = max(rightmax[n-i],A[n-i-1]);
    }
    int i=0,j=0,max_diff =-1;
    while (i<n && j<n){
        if (leftmin[i]<=rightmax[j]){
            max_diff = max(max_diff,j-i);
            j++;
        }
        else
            i++;
    }
    return max_diff;
}
