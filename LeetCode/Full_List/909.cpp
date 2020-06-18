class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(),quotient,remainder,row,col,rc;
        unordered_map<int,int> ump;
        ump[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int u = q.front();q.pop();
            if(u == n*n)
                return ump[u];
            for(int i = u+1; i<=min(u+6,n*n);i++){
                quotient = (i-1)/n;
                remainder = (i-1)%n;
                row = n-1-quotient;
                col = (row%2 != n%2) ? remainder: n-1-remainder;
                int v = (board[row][col] == -1 )? i : board[row][col];
                if(!ump.count(v)){
                    ump[v] = ump[u] + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};