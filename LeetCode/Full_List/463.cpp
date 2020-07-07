class Solution {
public:
    int dirs[5] = {-1,0,1,0,1};
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n ;j++)
                if(grid[i][j]==1){
                    int count = 0;
                    for(int k=0; k<4;k++){
                        int nr = i+dirs[k];
                        int nc = j+dirs[k+1];
                        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                            count++;
                        }
                    }
                    res += 4-count;
                }
        return res;
    }
};