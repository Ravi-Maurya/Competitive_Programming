void dfs(int i, int j, vector<string> &A){
    if(!(i<0 || i>=A.size() || j<0 || j>=A[0].size() || A[i][j]!='X')){
        A[i][j] = '_';
        dfs(i-1,j,A);
        dfs(i,j+1,A);
        dfs(i+1,j,A);
        dfs(i,j-1,A);
    }
}

int Solution::black(vector<string> &A) {
    int res = 0;
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A[0].size();j++)
        if(A[i][j]=='X'){
            res++;
            dfs(i,j,A);
        }
    return res;
}
