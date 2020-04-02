int Solution::canJump(vector<int> &A) {
    int n = A.size();
    if(n==1)
        return 1;
    int maxjump = A[0];
    for(int i=1;i<n;i++){
        if(i>maxjump)
            return 0;
        maxjump = max(maxjump,i+A[i]);
        if(maxjump>=n)
            return 1;
    }
    return 0;
}
