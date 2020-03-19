int Solution::solve(vector<string> &A) {
    sort(A.begin(),A.end());
    int n = A.size(),i,j,k;
    i = 0;
    j = n-1;
    while (i<j-1){
        double d = stod(A[i])+stod(A[j])+stod(A[i+1]);
        if (d>=2)
            j--;
        else if (d<=1)
            i++;
        else
            return 1;
    }
    return 0;
}
