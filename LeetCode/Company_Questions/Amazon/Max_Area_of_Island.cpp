class Solution {
public:
    vector<int> dirs = {-1,0,1,0,-1};
    void dfs(vector<vector<int>>& grid, int i, int j, int& res){
        grid[i][j] = 0;
        res++;
        for(int x=0;x<4;x++){
            int nr = dirs[x]+i;
            int nc = dirs[x+1]+j;
            if(0<=nr && nr<grid.size() && 0<=nc && nc<grid[0].size() && grid[nr][nc]==1)
                dfs(grid,nr,nc,res);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==1){
                    int count = 0;
                    dfs(grid,i,j,count);
                    res = max(res,count);
                }
            }
        }
        return res;
    }
};