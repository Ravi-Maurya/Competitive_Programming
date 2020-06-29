class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> rows,cols;
    int size;
    int d1,d2;
    TicTacToe(int n) {
        rows.resize(n,0);
        cols.resize(n,0);
        d1 = 0;
        d2 = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player==1){
            rows[row]++;
            cols[col]++;
            if(row==col)
                d1++;
            if(row+col == size -1 )
                d2++;
            if(rows[row]==size || cols[col]==size || d1 == size || d2 == size)
                return player;
            return 0;
        }
        else{
            rows[row]--;
            cols[col]--;
            if(row==col)
                d1--;
            if(row+col == size -1 )
                d2--;
            if(rows[row]==(-1*size) || cols[col]==(-1*size) || d1 == (-1*size) || d2 == (-1*size))
                return player;
            return 0;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */