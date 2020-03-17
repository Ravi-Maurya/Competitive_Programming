int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int a = A.size(),i=0;
    int b = B.size(),j=0;
    int c = C.size(),k=0;
    int ans = INT_MAX;
    while (i<a && j<b && k<c){
        int maxx = max(A[i],max(B[j],C[k]));
        int minn = min(A[i],min(B[j],C[k]));
        ans = abs(maxx-minn)<ans ? abs(maxx-minn) : ans;
        if (minn==A[i])
            i++;
        if (minn==B[j])
            j++;
        if (minn==C[k])
            k++;
    }
    return ans;
}
