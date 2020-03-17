vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = n-1;
    vector <int> ans(2,-1);
    while (i<j){
        int mid = (i+j)/2;
        if (A[mid]<B)
            i = mid+1;
        else
            j = mid;
    }
    if (A[i]!=B)
        return ans;
    ans[0] = i;
    j = n-1;
    while (i<j){
        int mid = 1 + (i+j)/2;
        if (A[mid]>B)
            j = mid-1;
        else
            i = mid;
    }
    ans[1] = j;
    return ans;
}
