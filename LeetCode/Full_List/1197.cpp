class Solution {
public:
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    bool visited[700][700];
    int minKnightMoves(int x, int y) {
        int steps = 0;
        if(x==0 && y==0)
            return steps;
        memset(visited,false,sizeof(visited));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0+300][0+300] = true;
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                auto curr = q.front();q.pop();
                for(int i=0; i<8; i++){
                    int nr = curr.first + dx[i];
                    int nc = curr.second + dy[i];
                    if(!visited[nr+300][nc+300]){
                        visited[nr+300][nc+300] = true;
                        if(nr==x && nc==y)
                            return steps;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return steps;
    }
};