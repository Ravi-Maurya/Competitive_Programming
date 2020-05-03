class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int num, int n){
        for(int j=0;j<n;j++)
            if(board[row][j]==(char)(num+48))
                return false;
        for(int i=0;i<n;i++)
            if(board[i][col]==(char)(num+48))
                return false;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if((row-row%3 + i < n) && (col-col%3 + j <n) && board[row-row%3 + i][col-col%3 + j] == (char)(num+48))
                    return false;
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col, int n){
        if(row==n){
            row = 0;
            col++;
            if(col==n)
                return true;
        }
        if(board[row][col]!='.')
            return solve(board, row+1, col, n);
        for(int num=1; num<=n; num++){
            if(isSafe(board,row,col,num,n)){
                board[row][col] = (char)(num+48);
                if(solve(board,row+1,col,n))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board,0,0,n);
    }
};