class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(!rows)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> distance(rows,vector<int>(cols,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(matrix[i][j]==0){
                    distance[i][j] = 0;
                    q.push({i,j});
                }
        vector<int> dirs = {-1,0,1,0,-1};
        while(!q.empty()){
            auto u = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nr = u.first + dirs[i];
                int nc = u.second + dirs[i+1];
                if(0<=nr && 0<=nc && nr<rows && nc<cols && distance[nr][nc]>distance[u.first][u.second]+1){
                    q.push({nr,nc});
                    distance[nr][nc] = distance[u.first][u.second]+1;
                }
            }
        }
        return distance;
    }
};