vector<int> x = {-1,-1,0,1,1,1,0,-1};
vector<int> y = {0,1,1,1,0,-1,-1,-1};

bool bfs(vector<vector<int>>& board, int s1, int s2, int d1, int d2){
    if(board[s1][s2]==-1 || board[d1][d2]==-1)
        return false;
    set<pair<int,int>> visited;
    queue<pair<int,int>> q;
    q.push({s1,s2});
    visited.insert({s1,s2});
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        if(u.first==d1 && u.second==d2)
            return true;
        for(int idx=0;idx<8;idx++){
            int u1 = u.first+x[idx];
            int u2 = u.second+y[idx];
            if(0<=u1 && u1<=d1 && 0<=u2 && u2<=d2 && board[u1][u2]!=-1 && visited.find({u1,u2})==visited.end()){
                q.push({u1,u2});
                visited.insert({u1,u2});
            }
        }
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> board(A+1,vector<int>(B+1,0));
    for(int i=0;i<=A;i++)
        for(int j=0;j<=B;j++)
            for(int k=0;k<C;k++)
                if(sqrt(pow(E[k]-i,2)+pow(F[k]-j,2))<=D)
                    board[i][j] = -1;
    if(bfs(board,0,0,A,B))
        return "YES";
    return "NO";
}
