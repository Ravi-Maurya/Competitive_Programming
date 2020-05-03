class Solution {
public:
    vector<vector<string>> solveNQueens(int n);
};
vector<string> intToQ(vector<vector<int>> &board, int n){
    vector<string> tmp(n);
    for(int i=0;i<n;i++)
        tmp[i] = ".";
    vector<string> res;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (board[i][j]!=0){
                tmp[j] = 'Q';
                break;
            }
        }
        string t = "";
        for(auto x:tmp)
            t.append(x);
        res.push_back(t);
        tmp[j] = ".";
    }
    return res;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    for(int j=0;j<col;j++)
        if (board[row][j]!=0)
            return false;
    int i=row;
    int j = col;
    while (i>=0 && j>=0){
        if (board[i][j]!=0)
            return false;
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i<n && j>=0){
        if(board[i][j]!=0)
            return false;
        i++;
        j--;
    }
    return true;
}

bool solveQ(vector<vector<string>> &res, vector<vector<int>> &board, int col, int n){
    if (col==n){
        vector<string> tmp = intToQ(board,n);
        res.push_back(tmp);
        return true;
    }
    bool r = false;
    for(int i=0;i<n;i++){
        if (isSafe(board,i,col,n)){
            board[i][col] = 1;
            r = (solveQ(res,board,col+1,n) || r);
            board[i][col] = 0;
        }
    }
    return r;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<int>> board(A,vector<int>(A,0));
    vector<vector<string>> res;
    bool tmp = solveQ(res,board,0,A);
    return res;
}
