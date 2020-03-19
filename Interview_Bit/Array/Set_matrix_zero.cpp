void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set <int> R, C;
    int n = A.size(), m = A[0].size(), i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if (A[i][j]==0){
                R.insert(i);
                C.insert(j);
            }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if (R.count(i))
                A[i][j] = 0;
            else if (C.count(j))
                A[i][j] = 0;
}
