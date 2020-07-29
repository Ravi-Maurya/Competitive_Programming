int Solution::findMedian(vector<vector<int> > &A) {
    if(A.empty())
        return 0;
    int n = A.size(), m = A[0].size();
    int mn = INT_MAX, mx = 0;
    for(int i=0; i<n; i++){
        mn = min(mn,A[i][0]);
        mx = max(mx,A[i][m-1]);
    }
    int mid = (n*m + 1)/2;
    while(mn<mx){
        int curr = mn + (mx-mn)/2;
        int count = 0;
        for(int i=0; i<n; i++){
            count += upper_bound(A[i].begin(),A[i].end(),curr) - A[i].begin();
        }
        if(count<mid)
            mn = curr + 1;
        else
            mx = curr;
    }
    return mn;
}
