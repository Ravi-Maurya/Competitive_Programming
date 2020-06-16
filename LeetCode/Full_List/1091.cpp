class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        int m = grid.size(),n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
            return -1;
        if(m==1 && n==1)
            return 1;
        vector<int> dirs = {-1,-1,0,1,1,1,0,-1,-1,-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        grid[0][0] = 1;
        while(!q.empty()){
            auto curr = q.front();q.pop();
            for(int i=0;i<8;i++){
                int nr = curr.second.first + dirs[i];
                int nc = curr.second.second + dirs[i+2];
                if(0<=nr && 0<=nc && nr<m && nc<n && grid[nr][nc]==0){
                    if(nr==(m-1) && nc==(n-1))
                        return curr.first+1;
                    q.push({curr.first+1,{nr,nc}});
                    grid[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};