class Solution {
public:
    int row, col;
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    bool isok(int x, int y) { return x>=0 && x<row && y>=0 && y<col; }
    
    void reveal(vector<vector<char>>& board, int x, int y)
    {
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int px = p.first, py = p.second;
            if(board[px][py]!='E') continue;
            
            int mines = 0;
            vector<pair<int,int>> tmp;
            for(int i=0; i<8; i++)
            {
                if(isok(px+dx[i], py+dy[i]))
                {
                    if(board[px+dx[i]][py+dy[i]]=='M') mines++;
                    else if(board[px+dx[i]][py+dy[i]]=='E') tmp.push_back({px+dx[i], py+dy[i]});
                }
            }
            if(!mines)
            {
                for(auto p:tmp) q.push(p);
                board[px][py] = 'B';
            }
            else board[px][py] = char(mines+48);
        }
    }
    
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        row = board.size(), col = board[0].size();
        int x = click[0], y = click[1];
        if(board[x][y]=='M') board[x][y]='X';
        else reveal(board, x, y);
        return board;
    }
};