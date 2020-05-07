class Solution {
    vector<int> dirs = {-1,0,1,0,-1};
    void dfs(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '2';
        for(int i=0; i<4; i++){
            int nr = row + dirs[i];
            int nc = col + dirs[i+1];
            if(0<=nr && nr<grid.size() && 0<=nc && nc<grid[0].size() && grid[nr][nc] == '1')
                dfs(grid,nr,nc);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};