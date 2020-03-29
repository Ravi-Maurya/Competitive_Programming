void dfs(int i, int j, vector<vector<char>> &A){
    if(!(i<0 || i>=A.size() || j<0 || j>=A[0].size() || A[i][j]!='-')){
        A[i][j] = 'O';
        dfs(i-1,j,A);
        dfs(i,j+1,A);
        dfs(i+1,j,A);
        dfs(i,j-1,A);
    }
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size(),m = A[0].size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(A[i][j]=='O')
                A[i][j]='-';
    for(int i=0;i<n;i++){
        if(A[i][0]=='-')
            dfs(i,0,A);
        if(A[i][m-1]=='-')
            dfs(i,m-1,A);
    }
    for(int j=0;j<m;j++){
        if(A[0][j]=='-')
            dfs(0,j,A);
        if(A[n-1][j]=='-')
            dfs(n-1,j,A);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(A[i][j]=='-')
                A[i][j]='X';
    
}
