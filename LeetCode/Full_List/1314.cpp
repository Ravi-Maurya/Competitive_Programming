class Solution {
public:
    
    int give(vector<vector<int>>& mat, int i, int j, int k, int m, int n){
        int sr = max(i-k,0);
        int er = min(i+k,m-1);
        int sc = max(j-k,0);
        int ec = min(j+k, n-1);
        int res = mat[er][ec];
        if(sr!=0)
            res -= mat[sr-1][ec];
        if(sc!=0)
            res -= mat[er][sc-1];
        if(sr!=0 && sc!=0)
            res += mat[sr-1][sc-1];
        return res;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=1; i<m; i++)
            for(int j=0; j<n; j++)
                mat[i][j] += mat[i-1][j];
        for(int j=1; j<n; j++)
            for(int i=0; i<m; i++)
                mat[i][j] += mat[i][j-1];
        vector<vector<int>> res(m,vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res[i][j] = give(mat,i,j,k,m,n);
            }
        }
        return res;
    }
};