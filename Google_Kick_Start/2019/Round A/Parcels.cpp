// BFS with binary search and optimization for k

#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;
#pragma GCC optimize ("-O3")

vector<int> x = {1,0,-1,0}, y = {0,-1,0,1};

bool check(long int k,vector<vector<int>>& board){
    int r = board.size(), c = board[0].size();
    int mina = r+c, minb = r+c, maxa = -r-c, maxb=-r-c;
    int counter = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (board[i][j]>k){
                counter++;
                mina = min(mina,i+j);
                maxa = max(maxa,i+j);
                minb = min(minb,i-j);
                maxb = max(maxb,i-j);
            }
        }
    }
    if(counter==0)
        return true;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (board[i][j]>0 && max(max(abs(mina - (i+j)),abs(maxa - (i+j))),max(abs(minb - (i-j)),abs(maxb - (i-j))))<=k ){
                return true;
            }
        }
    }
    return false;
}

int binary_srch(int l, int r, vector<vector<int>>& board){
    while(l<r){
        long int mid = (l+r)>>1;
        if(check(mid,board))
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

int bfs(vector<vector<int>>& board, queue<pair<int,int>>& q, vector<vector<bool>>& visited){
    int res = 0;
    while (!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = u.first + x[i];
            int nc = u.second + y[i];
            if( 0<=nr && nr<board.size() && 0<=nc && nc<board[0].size() && !visited[nr][nc]){
                board[nr][nc] = min(board[nr][nc], board[u.first][u.second] + 1);
                res = max(res,board[nr][nc]);
                visited[nr][nc] = 1;
                q.push(make_pair(nr,nc));
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> board(r,vector<int>(c,INT_MAX));
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(r,vector<bool>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                char c;
                cin >> c;
                if(c-'0' == 1){
                    visited[i][j] = 1;
                    board[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        int right = bfs(board, q, visited);
        int res = binary_srch(0, right, board);
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}