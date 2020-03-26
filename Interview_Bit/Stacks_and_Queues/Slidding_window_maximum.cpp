vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    if(B==1)
        return A;
    deque<int> q;
    int n = A.size(),i;
    B = min(B,n);
    for(i=0;i<B;i++){
        while(!q.empty() && A[i]>=A[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    vector<int> res;
    for(i=B;i<n;i++){
        res.push_back(A[q.front()]);
        while(!q.empty() && q.front()<=i-B)
            q.pop_front();
        while(!q.empty() && A[i]>=A[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    res.push_back(A[q.front()]);
    return res;
}
