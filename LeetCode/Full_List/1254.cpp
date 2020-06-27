class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int curr){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j]!=0)
            return;
        grid[i][j] = curr;
        dfs(grid,i+1,j,curr);
        dfs(grid,i,j+1,curr);
        dfs(grid,i,j-1,curr);
        dfs(grid,i-1,j,curr);
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            dfs(grid,i,0,-1);
            dfs(grid,i,m-1,-1);
        }
        for(int j=0; j<m; j++){
            dfs(grid,0,j,-1);
            dfs(grid,n-1,j,-1);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    res++;
                    dfs(grid,i,j,-1);
                }
            }
        }
        return res;
    }
};