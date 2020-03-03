void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    for (int x=0;x<n/2;x++){
        for(int y=x;y<n-x-1;y++){
            int tmp = A[x][y];
            A[x][y] = A[n-1-y][x];
            A[n-1-y][x] = A[n-1-x][n-1-y];
            A[n-1-x][n-1-y] = A[y][n-1-x];
            A[y][n-1-x] = tmp;
        }
    }
    return;
}
