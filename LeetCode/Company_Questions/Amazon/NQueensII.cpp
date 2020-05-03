class Solution {  
private:
	int res;
public:
	void dfs(int n,int dep,int r,int d1, int d2){
		if(dep==n){
			res++;
			return;
		}
		for(int i=0;i<n;i++){
			int cur=1<<i;
			if((cur&r) || (cur&d1) || (cur&d2)) continue;
			dfs(n,dep+1, (cur|r),(cur|d1)<<1,(cur|d2)>>1);
		}

	}
	int totalNQueens(int n) {
		res=0;
		dfs(n,0,0,0,0);
		return res;
	}
};

class Solution2 {
public:
    int totalNQueens(int n);
};
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

bool solveQ(int& res, vector<vector<int>>& board, int col, int n){
    if (col==n){
        res+=1;
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

int Solution2::totalNQueens(int A) {
    vector<vector<int>> board(A,vector<int>(A,0));
    int res = 0;
    bool tmp = solveQ(res,board,0,A);
    return res;
}
