vector<int> Solution::nextPermutation(vector<int> &A) {
    int len = A.size();
    int i,j;
    for(i = len - 2; i >= 0 ; i--)
        if(A[i] < A[i+1]) break;
    if (i == -1) {
        reverse(A.begin(), A.end());
        return A;
    }
    for(j = len - 1; j > i; j--)
        if(A[j] > A[i]) break;
    swap(A[i], A[j]);
    reverse(A.begin() + i + 1, A.end());
    return A;
}
