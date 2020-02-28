int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if (n<2) return 0;
    int maxx = A[0];
    int minn = A[0];
    for(int i=1;i<n;i++){
        maxx = max(A[i],maxx);
        minn = min(A[i],minn);
    }
    int gap = (maxx-minn-1)/(n-1) + 1;
    vector<int> min_bucket(n-1,INT_MAX);
    vector<int> max_bucket(n-1,INT_MIN);
    for(int i=0;i<n;i++){
        if (A[i]!=maxx && A[i]!=minn){
            int idx = (A[i]-minn)/gap;
            min_bucket[idx] = min(min_bucket[idx],A[i]);
            max_bucket[idx] = max(max_bucket[idx],A[i]);
        }
    }
    int max_gap = INT_MIN;
    int prev = minn;
    for(int i=0;i<n-1;i++){
        if (min_bucket[i]==INT_MAX && max_bucket[i]==INT_MIN)
            continue;
        max_gap = max(max_gap,min_bucket[i]-prev);
        prev = max_bucket[i];
    }
    max_gap = max(max_gap,maxx-prev);
    return max_gap;
}
