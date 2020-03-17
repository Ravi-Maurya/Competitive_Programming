int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    int i=0,j=1;
    while(i<=j&&j<n){
        if(i==j)
            j++;
        if(A[j]-A[i]==B)
            return 1;
        if(A[j]-A[i]<B)
            j++;
        if(A[j]-A[i]>B)
            i++;
    }
    return 0;
}
