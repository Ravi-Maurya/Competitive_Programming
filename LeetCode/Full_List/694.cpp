class Solution {
public:
    vector<vector<bool>> visited;
    unordered_set<string> seen;
    string signature;
    
    void dfs(vector<vector<int>>& grid, int i, int j, char val){
        if(0<=i && 0<=j && i<grid.size() && j<grid[0].size() && grid[i][j] == 1 && !visited[i][j]){
            visited[i][j] = true;
            signature += val;
            dfs(grid,i+1,j,'1');
            dfs(grid,i-1,j,'2');
            dfs(grid,i,j+1,'3');
            dfs(grid,i,j-1,'4');
            signature += '0';
        }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    signature = "";
                    dfs(grid,i,j,'0');
                    if(!seen.count(signature))
                        seen.insert(signature);
                }
            }
        }
        return seen.size();
    }
};