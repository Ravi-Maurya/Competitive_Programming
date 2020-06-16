class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<int> dirs = {-1,0,1,0,-1};
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(grid[i][j] == 2)
                    q.push({0,{i,j}});
        int res = 0;
        while(!q.empty()){
            auto curr = q.front();q.pop();
            res = max(res,curr.first);
            for(int i=0; i<4;i++){
                int nr = curr.second.first + dirs[i];
                int nc = curr.second.second + dirs[i+1];
                if(0<=nr && nr<m && 0<=nc && nc<n && grid[nr][nc]==1){
                    q.push({curr.first+1,{nr,nc}});
                    grid[nr][nc] = 2;
                }
            }
        }
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(grid[i][j] == 1)
                    return -1;
        return res;
    }
};