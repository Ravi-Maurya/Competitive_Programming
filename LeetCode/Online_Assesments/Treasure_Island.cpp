#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

vector<int> dir = {-1,0,1,0,-1};

int bfs(vector<vector<char>>& grid){
    int steps = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    if(grid[0][0]=='X')
        return 0;
    grid[0][0] = 'D';
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr = curr.first + dir[i], nc = curr.second + dir[i+1];
                if(0<=nr && nr<grid.size() && 0<=nc && nc<grid[0].size() && grid[nr][nc]!='D'){
                    if(grid[nr][nc]=='X')
                        return steps+1;
                    grid[nr][nc] = 'D';
                    q.push({nr,nc});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}