#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

void bfs(){
    vector<int> dir={-1,0,1,0,-1};
    int n,m;
    cin>>n>>m;
    vector<vector<int>> board(n,vector<int>(m));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]==0){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = top.first + dir[i];
            int nc = top.second + dir[i+1];
            if(0<=nr && nr<n && 0<=nc && nc<m && board[nr][nc]==-2){
                board[nr][nc] = 1 + board[top.first][top.second];
                q.push({nr,nc});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    bfs();
    return 0;
}