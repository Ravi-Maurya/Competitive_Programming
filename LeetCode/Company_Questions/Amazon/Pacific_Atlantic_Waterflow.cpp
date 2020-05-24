class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n == 0) return {};
        int m = matrix[0].size();
        
        vector<vector<int>> res;
        vector<vector<bool>> pacafic(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        for(int i=0; i<m; i++)
        {
            dfs(matrix, pacafic, INT_MIN, 0, i);
            dfs(matrix, atlantic, INT_MIN, n-1, i);
        }
        
        for(int i=0; i<n; i++)
        {
            dfs(matrix, pacafic, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, m-1);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(pacafic[i][j] && atlantic[i][j])
                    res.push_back(vector<int> {i,j});
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int prev, int i, int j)
    {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || prev > matrix[i][j] || visited[i][j]) return;
        
        visited[i][j] = true;
        dfs(matrix, visited, matrix[i][j], i+1, j);
        dfs(matrix, visited, matrix[i][j], i-1, j);
        dfs(matrix, visited, matrix[i][j], i, j+1);
        dfs(matrix, visited, matrix[i][j], i, j-1);
    }
};