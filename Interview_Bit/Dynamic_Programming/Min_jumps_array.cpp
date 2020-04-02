int Solution::jump(vector<int> &A) {
    int n = A.size();
    if (n==1)
        return 0;
    int jumps = 1;
    int maxJump = A[0];
    int nxtJump  = A[0];
    for(int i=1;i<n;i++){
        if(i>nxtJump)
            return -1;
        nxtJump = max(nxtJump,i+A[i]);
        if(i==maxJump && i!=n-1){
            maxJump = nxtJump;
            jumps++;
        }
    }
    return jumps;
}
