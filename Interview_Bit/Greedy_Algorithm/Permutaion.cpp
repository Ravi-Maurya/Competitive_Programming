vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int pos[n + 1];
    for (int i = 0; i < n; ++i)
        pos[A[i]] = i;
    for (int i = 0; i < n && B; ++i) {
        if (A[i] == n - i)
            continue;
        int temp = pos[n - i];
        pos[A[i]] = pos[n - i];
        pos[n - i] = i;
        swap(A[temp], A[i]);
        B--;
    }
    return A;
}
