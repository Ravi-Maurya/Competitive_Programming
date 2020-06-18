class Solution {
public:
    int row, col;
    int dirs[10] = {-1,-1,0,1,1,1,0,-1,-1,-1};
    
    void reveal(vector<vector<char>>& board, int x, int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            auto curr = q.front();q.pop();
            int px = curr.first, py = curr.second;
            if(board[px][py]!='E')
                continue;
            int mines = 0;
            vector<pair<int,int>> tmp;
            for(int i=0; i<8; i++){
                int nr = px+dirs[i];
                int nc = py+dirs[i+2];
                if(0<=nr && 0<=nc && nr<row && nc<col){
                    if(board[nr][nc]=='M')
                        mines++;
                    else if(board[nr][nc]=='E')
                        tmp.push_back({nr,nc});
                }
            }
            if(!mines){
                for(auto p:tmp)
                    q.push(p);
                board[px][py] = 'B';
            }
            else
                board[px][py] = char(mines+48);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        row = board.size(), col = board[0].size();
        int x = click[0], y = click[1];
        if(board[x][y]=='M')
            board[x][y]='X';
        else
            reveal(board, x, y);
        return board;
    }
};