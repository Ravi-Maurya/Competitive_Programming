void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<int> row,col;
    int r = A.size(),i;
    int c = A[0].size(),j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(A[i][j]==0){
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(row.find(i)!=row.end() || col.find(j)!=col.end()){
                A[i][j] = 0;
            }
        }
    }
    return;
}
