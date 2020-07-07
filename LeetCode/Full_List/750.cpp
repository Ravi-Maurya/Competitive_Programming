class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {//O(n4)
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        if(n==1 || m==1)
            return 0;
        int res = 0;
        vector<vector<int>> rows(m), cols(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    for(auto c: rows[i]){
                        for(auto r:cols[j]){
                            if(grid[r][c]==1)
                                res++;
                        }
                    }
                    rows[i].push_back(j);
                    cols[j].push_back(i);
                }
            }
        }
        return res;
    }
};