class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dirs = {-1,-1,0,1,1,1,0,-1,-1,-1};
        int r = board.size(), c = board[0].size();
        vector<vector<int>> res = board;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int live =  0;
                for(int k = 0; k<8; k++){
                    int nr = i+dirs[k];
                    int nc = j+dirs[k+2];
                    if(0<=nr && 0<=nc && nr<r && nc<c && res[nr][nc]==1)
                        live++;
                }
                if(res[i][j]==1 && live<2 || live>3)
                    board[i][j] = 0;
                if(res[i][j]==0 && live==3)
                    board[i][j] = 1;
            }
        }
        return;
    }
};