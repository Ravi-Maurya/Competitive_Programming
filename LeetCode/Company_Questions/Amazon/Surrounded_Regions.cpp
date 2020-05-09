class Solution {
    vector<int> dirs = {-1,0,1,0,-1};
    void dfs(int i, int j, vector<vector<char>>& board){
        if(!(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='-')){
            board[i][j] = 'O';
            for(int k=0;k<4;k++){
                dfs(i+dirs[k], j+dirs[k+1], board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(!n)
            return;
        int m = board[0].size();
        if(!m)
            return;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j]=='O')
                    board[i][j] = '-';
        
        for(int i=0; i<n; i++){
            if(board[i][0]=='-')
                dfs(i,0,board);
            if(board[i][m-1]=='-')
                dfs(i,m-1,board);
        }
        for(int j=0; j<m; j++){
            if(board[0][j] == '-')
                dfs(0,j,board);
            if(board[n-1][j]=='-')
                dfs(n-1,j,board);
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j]=='-')
                    board[i][j] = 'X';
        return;
    }
};