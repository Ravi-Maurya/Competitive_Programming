class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j){
        vector<int> dirs = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()){
            auto curr = q.front();q.pop();
            for(int k = 0; k<4; k++){
                int nr = curr.first + dirs[k];
                int nc = curr.second + dirs[k+1];
                if(0<=nr && 0<=nc && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]=='1'){
                    grid[nr][nc] = '0';
                    q.push({nr,nc});
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i <grid.size(); i++)
            for(int j = 0; j<grid[0].size(); j++)
                if(grid[i][j]=='1'){
                    res++;
                    bfs(grid,i,j);
                }
        return res;
    }
};