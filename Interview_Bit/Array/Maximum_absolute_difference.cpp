int Solution::maxArr(vector<int> &A) {
    int n = A.size(),i;
    int max1 = INT_MIN, max2 = INT_MIN, min1=INT_MAX, min2 = INT_MAX;
    for(i=0;i<n;i++){
        max1 = max(max1,A[i]+i+1);
        max2 = max(max2,A[i]-i-1);
        min1 = min(min1,A[i]+i+1);
        min2 = min(min2,A[i]-i-1);
    }
    return max(abs(max1-min1),abs(max2-min2));
}