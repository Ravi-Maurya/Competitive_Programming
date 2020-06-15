class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> visited;
        visited.clear();
        for(int i=0; i<9; i++){
            visited.clear();
            for(int j=0; j<9; j++){
                if(board[i][j] != '.' && visited.count(board[i][j]))
                    return false;
                visited.insert(board[i][j]);
            }
        }
        // cout<<"ROW == OK - d\n";
        for(int j=0; j<9; j++){
            visited.clear();
            for(int i=0; i<9; i++){
                if(board[i][j]!='.' && visited.count(board[i][j]))
                    return false;
                visited.insert(board[i][j]);
            }
        }
        // cout<<"Col == OK - d\n";
        vector<int> dirs = {0,-1,-1,-1,0,1,1,1,0,-1};
        for(int i = 1; i<9; i+=3){
            for(int j = 1; j<9; j+=3){
                visited.clear();
                visited.insert(board[i][j]);
                // cout<<i<<" "<<j<<"\n";
                for(int k=0; k<8;k++){
                    int nr = i + dirs[k];
                    int nc = j + dirs[k+2];
                    // cout<<nr<< " "<< nc<<" -d\n";
                    if(board[nr][nc] != '.' && visited.count(board[nr][nc]))
                        return false;
                    visited.insert(board[nr][nc]);
                }
            }
        }
        // cout<<"3x3 == OK - d\n";
        return true;
    }
};