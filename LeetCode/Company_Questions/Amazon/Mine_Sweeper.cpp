class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.empty()) return {};
        
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        vector<int> adj = {0,1,-1};
        stack<pair<int,int>> st;
        map<pair<int,int>,bool> visited;
        vector<pair<int,int>> neighbours;  
        
        st.push({click[0],click[1]});
        
        int rows = board.size(), cols = board[0].size();
        
        while(st.empty() == false){
            
            auto curr = st.top();
            st.pop();
            
            auto x = curr.first, y = curr.second, mines = 0;
            
            if(visited[{x,y}])
                continue;
            
            neighbours = {};
          
            for(int i = 0; i < adj.size();++i)
                for(int j = 0;j < adj.size();++j){
                    
                    if((adj[i]==adj[j] and adj[j]==0) == false){
                        int r = adj[i] + x, c = adj[j] + y;
                        
                        if(r >= 0 and r<rows and c>=0 and c<cols){
                            
                            auto curr_cell = board[r][c];
                            
                            if(curr_cell == 'M')
                                mines++;
                            else if(curr_cell == 'E' and visited[{x,y}] == false)
                                neighbours.push_back({r,c});    
                        }
                        
                    }
                    
                }
            
            
            if(mines == 0){
              board[x][y] = 'B';
              
              for(auto i : neighbours)
                st.push(i);
              
            }
            else{
                if(board[x][y] != 'M')
                    board[x][y] = mines + '0';
            }
                
            
            visited[{x,y}] = true;
            
        }
        
        return board;
    }
};