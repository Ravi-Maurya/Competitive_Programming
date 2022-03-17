int Solution::bulbs(vector<int> &A) {
    int res = 0;
    int n = A.size(),i;
    if(n==0)
        return 0;
    for(i=0;i<n-1;i++){
        if((A[i]==0 && A[i+1]==1)||(A[i]==1 && A[i+1]==0))
            res++;
    }
    if(A[0]==1)
        return res;
    return res+1;
}


int Solution::bulbs(vector<int> &A) {
    int mult = 1;
    int count = 0;
    for(int i = 0; i<A.size(); i++){
        if((A[i]==0 && mult==1) || (A[i]==1 && mult==-1)){
            mult *= -1;
            count++;
        }
    }
    return count;
}
