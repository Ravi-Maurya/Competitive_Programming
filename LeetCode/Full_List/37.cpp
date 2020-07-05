class Solution {
public:
    void solveSudoku(vector<vector<char>>& board);
};

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

bool solve(vector<vector<int>> &board, int row, int col, int n){
    if(row==n){
        row=0;
        col++;
        if(col==n)
            return true;
    }
    if(board[row][col]!=0)
        return solve(board,row+1,col,n);
    for(int num = 1; num<=n;num++){
        if (isSafe(board,row,col,num,n)){
            board[row][col] = num;
            if (solve(board,row+1,col,n))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    int n = A.size();
    vector<vector<int>> board(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (A[i][j] != '.')
                board[i][j] = (int)(A[i][j]-'0');
    bool tmp = solve(board,0,0,n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (A[i][j]== '.'){
                // cout<<A[i][j]<<board[i][j]<<"\n";
                A[i][j] = (char)(board[i][j]+48);
            }
}
