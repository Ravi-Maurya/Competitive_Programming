class Solution {
public:
    int curr;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]==0)
            return;
        curr++;
        grid[i][j] = 0;
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int res = INT_MIN;
        for(int i=0; i<grid.size(); i++){
            for(int j=0 ;j<grid[0].size() ;j++){
                if(grid[i][j]==1){
                    curr = 0;
                    dfs(grid,i,j);
                    res = max(res,curr);
                }
            }
        }
        return (res==INT_MIN?0:res);
    }
};