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


class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i <grid.size(); i++)
            for(int j = 0; j<grid[0].size(); j++)
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j);
                }
        return res;
    }
};