vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size(),left = -1,right =-1,i;
    int tmp;
    tmp = A[0];
    for(i=1;i<n;i++){
        if (A[i]<tmp)
            right = i;
        tmp = max(tmp,A[i]);
    }
    tmp = A[n-1];
    for(i=n-1;i>=0;i--){
        if (A[i]>tmp)
            left = i;
        tmp = min(tmp,A[i]);
    }
    if (left==-1)
        return {-1};
    return {left,right};
}
