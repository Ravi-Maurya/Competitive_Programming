class Solution {
public:
    int get(int s, int n){
        int quot = (s-1)/n;
        int rem = (s-1)%n;
        int row = n-1-quot;
        int col = row%2 != n%2 ? rem: n-1-rem;
        return row*n + col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        unordered_map<int,int> distance;
        distance[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            auto curr = q.front();q.pop();
            if(curr == N*N)
                return distance[curr];
            for(int nxt = curr+1; nxt<=min(curr+6, N*N); ++nxt){
                int rc = get(nxt,N);
                int r = rc/N, c = rc%N;
                int nxt_final = board[r][c]==-1 ? nxt: board[r][c];
                if(!distance.count(nxt_final)){
                    distance[nxt_final] = distance[curr] + 1;
                    q.push(nxt_final);
                }
            }
        }
        return -1;
    }
};