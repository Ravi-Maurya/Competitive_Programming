void dfs(vector<vector<int>> &matrix, vector<vector<int>> &ocean, int i, int j, int prev) {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return;
        }
        if(matrix[i][j] < prev || ocean[i][j] == 1) {
            return;
        }
        ocean[i][j] = 1;
        dfs(matrix, ocean, i - 1, j, matrix[i][j]);
        dfs(matrix, ocean, i, j - 1, matrix[i][j]);
        dfs(matrix, ocean, i + 1, j, matrix[i][j]);
        dfs(matrix, ocean, i, j +1, matrix[i][j]);
    }

int Solution::solve(vector<vector<int> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> Pac(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> Alt(matrix.size(), vector<int>(matrix[0].size(), 0));
        int height = matrix.size();
        int width = matrix[0].size();
        for(int i = 0; i < height;i++) {
            dfs(matrix, Pac, i, 0, matrix[i][0]);
            dfs(matrix, Alt, i, width - 1, matrix[i][width - 1]);
        }

        for(int i = 0; i < width;i++) {
            dfs(matrix, Pac, 0, i, matrix[0][i]);
            dfs(matrix, Alt, height - 1, i, matrix[height - 1][i]);
        }
        int count = 0;
        for(int i = 0; i < matrix.size();i++) {
            for(int j = 0; j < matrix[0].size();j++) {
                if(Pac[i][j] == 1 && Alt[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
