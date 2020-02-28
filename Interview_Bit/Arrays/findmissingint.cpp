int Solution::firstMissingPositive(vector<int> &A) {
    for(int i = 0; i < A.size();){
        if(A[i] - 1 >= 0 && A[i] - 1 < A.size()) {
            swap(A[A[i]-1], A[i]);
        }
        if(A[i] <= 0 || A[i] == i+1 || A[i] > A.size() || A[A[i]-1] == A[i])
            ++i;
    }
    for(int i = 0; i < A.size(); i++)
        if(A[i] != i + 1)
            return i + 1;
    return A.size() + 1;
}