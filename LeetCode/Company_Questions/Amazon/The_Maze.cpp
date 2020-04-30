#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        vector<int> dirs = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        visited[start[0]][start[1]] = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first==destination[0] && curr.second==destination[1])
                return true;
            for(int k=0; k<4; k++){
                int nr = curr.first + dirs[k];
                int nc = curr.second + dirs[k+1];
                while(0<=nr && 0<=nc && nr<m && nc<n && maze[nr][nc]==0)
                    nr += dirs[k], nc += dirs[k+1];
                nr -= dirs[k], nc -= dirs[k+1];
                if(!visited[nr][nc]){
                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        return false;
    }
}