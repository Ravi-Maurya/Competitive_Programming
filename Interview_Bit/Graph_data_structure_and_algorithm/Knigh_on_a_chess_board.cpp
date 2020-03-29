int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> board(A,vector<int>(B,0));
    if(C==E && D==F)
        return 0;
    vector<int> dx = {-2,-1,1,2,2,1,-1,-2};
    vector<int> dy = {1,2,2,1,-1,-2,-2,-1};
    board[C-1][D-1] = 1;
    queue<pair<int,int>> q;
    q.push({C-1,D-1});
    int res = 0;
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int x = curr.first+dx[i];
            int y = curr.second+dy[i];
            if(0<=x && x<A && 0<=y && y<B && board[x][y]==0){
                board[x][y] = board[curr.first][curr.second]+1;
                q.push({x,y});
                if (x==E-1 && y==F-1)
                    return board[x][y]-1;
            }
        }
    }
    return res-1;
}
