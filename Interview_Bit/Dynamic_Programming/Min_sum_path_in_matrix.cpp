int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
                continue;
            else if(i==0)
                A[i][j] += A[i][j-1];
            else if(j==0)
                A[i][j] += A[i-1][j];
            else
                A[i][j] += min(A[i-1][j],A[i][j-1]);
        }
    }
    return A[m-1][n-1];
}
