class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int count, int i, int j){
        if(word.size()==count)
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[count])
            return false;
        char tmp = board[i][j];
        board[i][j] = ' ';
        bool res = dfs(board,word, count+1, i+1, j) || dfs(board,word, count+1, i-1, j)
            || dfs(board,word, count+1, i, j+1) || dfs(board,word, count+1, i, j-1);
        board[i][j] = tmp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(dfs(board,word,0,i,j))
                    return true;
        return false;
    }
};