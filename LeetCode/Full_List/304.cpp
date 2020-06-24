class NumMatrix {
    private:
    vector<vector<int>> bit;
    int n, m;
    public:
    NumMatrix(vector<vector<int>>& matrix){
        if(matrix.empty())
            return;
        n = matrix.size();
        m = matrix[0].size();
        bit.resize(n,vector<int>(m,0));
        for(int i=0; i<n; i++)
            for(int j=0; j<m;j++)
                update(i,j,matrix[i][j]);
    }
    
    void update(int x, int y, int val){
        for(int i=x; i<n; i = i | (i+1)){
            for(int j=y; j<m; j = j | (j+1)){
                bit[i][j] += val;
            }
        }
    }
    
    int query1(int x, int y){
        int res = 0;
        for(int i=x; i>=0; i = (i&(i+1)) - 1){
            for(int j=y; j>=0; j = (j&(j+1)) - 1){
                res += bit[i][j];
            }
        }
        return res;
    }

    int sumRegion(int x1, int y1, int x2, int y2){
        if(n==0 && m==0)
            return 0;
        int v1 = query1(x2,y2);
        int v2 = query1(x1-1,y1-1);
        int v3 = query1(x1-1,y2);
        int v4 = query1(x2,y1-1);
        return (v1 + v2 - v3 - v4);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */