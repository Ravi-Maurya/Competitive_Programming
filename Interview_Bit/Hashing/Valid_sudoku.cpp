bool isSafe(vector<vector<int>> &board, int row, int col, int num, int n){
    for(int j=0;j<n;j++)
        if (board[row][j]==num)
            return false;
    for(int i=0;i<n;i++)
        if(board[i][col]==num)
            return false;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if ((row-row%3 +i<n) && (col-col%3 +j<n) && board[row-row%3 +i][col-col%3 +j]==num)
                return false;
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    int n = A.size();
    vector<vector<int>> board(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (A[i][j] != '.')
                board[i][j] = (int)(A[i][j]-'0');
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(board[i][j]!=0){
                int val=board[i][j];
                board[i][j]=0;
                if(!isSafe(board,i,j,val,n))
                    return 0;
                board[i][j]=val;
            }
        }
    return 1;
}
