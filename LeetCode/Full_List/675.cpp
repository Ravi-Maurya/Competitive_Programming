class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    int bfs(vector<vector<int>>& forest, int sr, int sc, int er, int ec){
        if(sr==er && sc==ec)
            return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> visited(m,vector<int>(n,0));
        visited[sr][sc] = 1;
        int step = 0;
        while(!q.empty()){
            step++;
            int size = q.size();
            while(size--){
                auto curr = q.front();q.pop();
                for(int i=0; i<4; i++){
                    int nr = curr.first + dirs[i];
                    int nc = curr.second + dirs[i+1];
                    if(nr<0 || nc<0 || nr>=m || nc>=n || visited[nr][nc]==1 || forest[nr][nc]==0)
                        continue;
                    if(nr==er && nc==ec)
                        return step;
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.empty() || forest[0].empty())
            return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(forest[i][j]>1)
                    trees.push_back({forest[i][j],i,j});
        sort(trees.begin(),trees.end());
        int res = 0;
        for(int i=0, row =0, col = 0; i<trees.size(); i++){
            int step = bfs(forest,row,col,trees[i][1],trees[i][2]);
            if(step==-1)
                return -1;
            res += step;
            row = trees[i][1];
            col = trees[i][2];
        }
        return res;
    }
};