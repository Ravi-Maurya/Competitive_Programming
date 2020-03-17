int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int l = 0, r = n-1;
    int ans = 0;
    while (l<r){
        ans = max(ans,min(A[l],A[r])*(r-l));
        if (A[l]<A[r])
            l++;
        else
            r--;
    }
    return ans;
}
