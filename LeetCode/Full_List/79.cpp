class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx){
        if(idx==word.size())
            return true;
        if(idx>word.size() || i>=board.size() || i<0 || j>=board[0].size() || j<0 || word[idx]!=board[i][j])
            return false;
        char tmp = board[i][j];
        board[i][j] = '.';
        if(dfs(board,i,j+1,word,idx+1))
            return true;
        if(dfs(board,i+1,j,word,idx+1))
            return true;
        if(dfs(board,i,j-1,word,idx+1))
            return true;
        if(dfs(board,i-1,j,word,idx+1))
            return true;
        board[i][j] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
            for(int j= 0; j<board[0].size(); j++)
                if(word[0]==board[i][j] && dfs(board,i,j,word,0))
                    return true;
        return false;
    }
};