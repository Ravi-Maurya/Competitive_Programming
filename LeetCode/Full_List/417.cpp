class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int r, int c){
        ocean[r][c] = true;
        if(r>0 && matrix[r-1][c]>=matrix[r][c] && !ocean[r-1][c])
            dfs(matrix,ocean,r-1,c);
        if(r<(matrix.size()-1) && matrix[r+1][c]>=matrix[r][c] && !ocean[r+1][c])
            dfs(matrix,ocean,r+1,c);
        if(c>0 && matrix[r][c-1]>=matrix[r][c] && !ocean[r][c-1])
            dfs(matrix,ocean,r,c-1);
        if(c<(matrix[0].size()-1) && matrix[r][c+1]>=matrix[r][c] && !ocean[r][c+1])
            dfs(matrix,ocean,r,c+1);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int n = matrix.size(),m = matrix[0].size();
        if(n*m == 1)
            return {{0,0}};
        vector<vector<bool>> pacific(n,vector<bool>(m,false)), atlantic(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs(matrix,pacific,i,0);
            dfs(matrix,atlantic,i,m-1);
        }
        for(int j=0; j<m; j++){
            dfs(matrix,pacific,0,j);
            dfs(matrix,atlantic,n-1,j);
        }
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
        return res;
    }
};