int Solution::uniquePaths(int A, int B) {
    if (A==1 || B==1)
        return 1;
    vector<vector<int>> grid(A,vector<int>(B,0));
    grid[0][0] = 1;
    for(int i=0;i<A;i++)
        for (int j=0;j<B;j++){
            if (i==0 && j==0)
                grid[i][j] = 1;
            else if(i==0)
                grid[i][j] = grid[i][j-1];
            else if(j==0)
                grid[i][j] = grid[i-1][j];
            else
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
        }
    return grid[A-1][B-1];
}
