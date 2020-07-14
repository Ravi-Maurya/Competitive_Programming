class Solution {
public:
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<int>>& maze, vector<int> start, vector<int>& destination){
        if(visited[start[0]][start[1]])
            return false;
        if(start[0]==destination[0] && start[1] == destination[1])
            return true;
        visited[start[0]][start[1]] = 1;
        int r = start[1] + 1, l = start[1] - 1 , u = start[0] - 1, d = start[0] + 1;
        while(r<maze[0].size() && maze[start[0]][r]==0)
            r++;
        if(dfs(maze,{start[0],r-1},destination))
            return true;
        
        while(l>=0 && maze[start[0]][l]==0)
            l--;
        if(dfs(maze,{start[0],l+1},destination))
            return true;
        
        while(u>=0 && maze[u][start[1]]==0)
            u--;
        if(dfs(maze,{u+1,start[1]},destination))
            return true;
        
        while(d<maze.size() && maze[d][start[1]]==0)
            d++;
        if(dfs(maze,{d-1,start[1]},destination))
            return true;
        
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m = maze[0].size();
        visited.resize(n,vector<bool>(m,false));
        return dfs(maze,start, destination);
    }
};