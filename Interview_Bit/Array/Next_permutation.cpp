vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size(),i;
    int invert = n-2;
    while (invert>=0 && A[invert]>=A[invert+1]) invert--;
    if (invert==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    for(i = n-1; i>=invert+1; i--){
        if (A[i]>A[invert]){
            swap(A[i],A[invert]);
            break;
        }
    }
    reverse(A.begin()+(invert+1),A.end());
    return A;
}
