class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({A[0][0],{0,0}});
        vector<vector<int>> visited(m,vector<int>(n,INT_MIN));
        visited[0][0] = A[0][0];
        while(!pq.empty()){
            auto curr = pq.top();pq.pop();
            int x = curr.second.first, y = curr.second.second;
            int value = curr.first;
            if(x==m-1 && y==n-1)
                return value;
            for(int i=0; i<4; i++){
                int nr = x + dirs[i];
                int nc = y + dirs[i+1];
                if(nr<0 || nc<0 || nr>=m || nc>=n)
                    continue;
                if(visited[nr][nc]<min(visited[x][y],A[nr][nc])){
                    visited[nr][nc] = min(visited[x][y],A[nr][nc]);
                    pq.push({visited[nr][nc],{nr,nc}});
                }
            }
        }
        return visited[m-1][n-1];
    }
};