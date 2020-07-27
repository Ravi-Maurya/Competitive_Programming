/*
499. The Maze III
Hard

194

41

Add to List

Share
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.

Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.

 

Example 1:

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (0, 1)

Output: "lul"

Explanation: There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".

Example 2:

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (3, 0)

Output: "impossible"

Explanation: The ball cannot reach the hole.

 

Note:

There is only one ball and one hole in the maze.
Both the ball and hole exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.
*/

class Solution {//bug
public:
    int diry[4] = {0,-1,1,0};
    int dirx[4] = {1,0,0,-1};
    char dirs[4] = {'d','l','r','u'};
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        distance[ball[0]][ball[1]] = 0;
        string res = "";
        queue<pair<string,pair<int,int>>> q;
        q.push({"",{ball[0],ball[1]}});
        while(!q.empty()){
            auto curr = q.front();q.pop();
            for(int i=0; i<4; i++){
                int x = curr.second.first + dirx[i];
                int y = curr.second.second + diry[i];
                int count = 0;
                while(0<=x && 0<=y && x<m && y<n && maze[x][y]==0){
                    count++;
                    if(x==hole[0] && y==hole[1]){
                        if(distance[curr.second.first][curr.second.second] + count < distance[x][y]){
                            distance[x][y] = distance[curr.second.first][curr.second.second] + count;
                            res = curr.first + dirs[i];
                        }
                        else if(distance[curr.second.first][curr.second.second] + count == distance[x][y])
                            if(res > curr.first + dirs[i])
                                res = curr.first + dirs[i];
                    }
                    x += dirx[i];
                    y += diry[i];
                }
                if(distance[curr.second.first][curr.second.second] + count < distance[x-dirx[i]][y-diry[i]]){
                    distance[x-dirx[i]][y-diry[i]] = distance[curr.second.first][curr.second.second] + count;
                    q.push({curr.first + dirs[i],{x-dirx[i],y-diry[i]}});
                }
            }
        }
        if(res.size()==0)
            return "impossible";
        return res;
    }
};


// solution
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        vector<vector<string>> path(m, vector<string>(n));
        // distance of starting point is 0
        dis[ball[0]][ball[1]] = 0;
        queue<vector<int>> myq;
        myq.push(ball);
       // the order of ball move direction is lexicographically smallest, i.e. dlru
        vector<int> d1({1, 0, 0, -1}), d2({0, -1, 1, 0});
        string dirs = "dlru";
        while (!myq.empty()) {
            int row = myq.front()[0], col = myq.front()[1];
            myq.pop();
            for (int i = 0; i < 4; ++i) {
                int r = row+d1[i], c = col+d2[i], len = 0;
                while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0) {
                    r += d1[i];
                    c += d2[i];
                    len++;
                }
                r -= d1[i];
                c -= d2[i];
                // if the current move goes across the hole
                if ((hole[0]-row)*(hole[0]-r) <= 0 && (hole[1]-col)*(hole[1]-c) <= 0) {
                    int k = abs(hole[0]-row)+abs(hole[1]-col);
                    if (dis[hole[0]][hole[1]] > dis[row][col]+k || (dis[hole[0]][hole[1]] == dis[row][col]+k && path[hole[0]][hole[1]] > path[row][col]+dirs[i])) {
                        dis[hole[0]][hole[1]] = dis[row][col]+k;
                        path[hole[0]][hole[1]] = path[row][col]+dirs[i];
                    }
                    continue;
                }
                // check whether the end point should be a new starting point
                if (dis[r][c] > dis[row][col]+len || (dis[r][c] == dis[row][col]+len && path[r][c] > path[row][col]+dirs[i])) {
                    dis[r][c] = dis[row][col]+len;
                    path[r][c] = path[row][col]+dirs[i];
                    myq.push({r, c});
                }
            }
        }
        return path[hole[0]][hole[1]] == ""? "impossible":path[hole[0]][hole[1]];
    }
};