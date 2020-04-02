int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int res = INT_MIN;
    for(int i=m-1;i>=0;i--)
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1){
                res = max(res,A[i][j]);
            }
            else if(i==m-1){
                A[i][j] += A[i][j+1];
                res = max(res,A[i][j]);
            }
            else if(j==n-1){
                A[i][j] += A[i+1][j];
                res = max(res,A[i][j]);
            }
            else{
                A[i][j] += (A[i][j+1] + A[i+1][j] - A[i+1][j+1]);
                res = max(res,A[i][j]);
            }
        }
    return res;
}
