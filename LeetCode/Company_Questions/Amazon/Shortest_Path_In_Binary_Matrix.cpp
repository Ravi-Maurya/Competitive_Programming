class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m)
            return -1;
        int n = grid[0].size();
        if(!n)
            return -1;
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
            return -1;
        vector<int> dirs = {-1,-1,0,1,1,1,0,-1,-1,-1};
        queue<pair<int,pair<int,int>>> bfs;
        bfs.push({1,{0,0}});
        grid[0][0] = 1;
        while(!bfs.empty()){
            auto curr = bfs.front(); bfs.pop();
            if(curr.second.first == m-1 && curr.second.second == n-1)
                return curr.first;
            for(int i=0;i<8;i++){
                int nr = curr.second.first + dirs[i];
                int nc = curr.second.second + dirs[i+2];
                if(0<=nr && 0<=nc && nr<m && nc<n && !grid[nr][nc]){
                    grid[nr][nc] = 1;
                    bfs.push({curr.first+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};