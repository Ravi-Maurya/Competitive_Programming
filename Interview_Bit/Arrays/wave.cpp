vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    int N = A.size();
    for(int i = 0; i < N - 1; i += 2) {
        swap(A[i], A[i + 1]);
    }
    return A;
}