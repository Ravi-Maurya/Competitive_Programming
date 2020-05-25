#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

void bfs(vector<string>& chess, int n, int m, int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    chess[i][j] = '-';
    vector<int> dirs = {-1,0,1,0,-1};
    vector<char> chessman = {'B','W'};
    int st = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto curr = q.front();q.pop();
            chess[curr.first][curr.second] = chessman[st];
            for(int i=0; i<4; i++){
                int nr = curr.first+ dirs[i];
                int nc = curr.second + dirs[i+1];
                if(0<=nr && 0<=nc && nr<n && nc<m && chess[nr][nc]=='.'){
                    chess[nr][nc] = '-';
                    q.push({nr,nc});
                }
            }
        }
        st = 1-st;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> chess(n);
    for(int i=0 ;i<n; i++)
        cin>>chess[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(chess[i][j] == '.')
                bfs(chess,n,m,i,j);
    for (int i = 0; i < n; i++){
        cout<<chess[i]<<"\n";
    }
    return 0;
}