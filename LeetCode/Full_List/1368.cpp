class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<int> dirx = {0,0,1,-1};
        vector<int> diry = {1,-1,0,0};
        vector<int> val = {1,2,3,4};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        cost[0][0] = 0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = curr.first + dirx[i];
                int nc = curr.second + diry[i];
                int v = val[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !visited[nr][nc]){
                    bool flag = false;
                    if(grid[curr.first][curr.second] == v){
                        if(cost[nr][nc]>cost[curr.first][curr.second]){
                            flag = true;
                            cost[nr][nc] = cost[curr.first][curr.second];
                        }
                    }
                    else{
                        if(cost[nr][nc]>cost[curr.first][curr.second]+1){
                            flag = true;
                            cost[nr][nc] = cost[curr.first][curr.second]+1;
                        }
                    }
                    if(flag)
                        q.push({nr,nc});
                }
            }
        }
        return cost[m-1][n-1];
        
    }
};