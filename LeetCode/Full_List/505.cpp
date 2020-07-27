/*
505. The Maze II
Medium

602

27

Add to List

Share
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

 

Example 1:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12

Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1

Explanation: There is no way for the ball to stop at the destination.

 

Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/


class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        distance[start[0]][start[1]] = 0;
        int dirs[5] = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        while(!q.empty()){
            auto curr = q.front();q.pop();
            for(int i=0; i<4; i++){
                int x = curr.first + dirs[i];
                int y = curr.second + dirs[i+1];
                int count = 0;
                while(0<=x && 0<=y && x<m && y<n && maze[x][y]==0){
                    x += dirs[i];
                    y += dirs[i+1];
                    count++;
                }
                if(distance[curr.first][curr.second] + count < distance[x-dirs[i]][y-dirs[i+1]]){
                    distance[x-dirs[i]][y-dirs[i+1]] = distance[curr.first][curr.second] + count;
                    q.push({x-dirs[i],y-dirs[i+1]});
                }
            }
        }
        return (distance[destination[0]][destination[1]]==INT_MAX? -1 : distance[destination[0]][destination[1]]);
    }
};


class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    void dijkstra(vector<vector<int>>& maze, vector<int>& start,vector<vector<int>>& distance){
        int m = maze.size(), n = maze[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{start[0],start[1]}});
        while(!pq.empty()){
            auto curr = pq.top();pq.pop();
            if(distance[curr.second.first][curr.second.second] < curr.first)
                continue;
            for(int i=0; i<4; i++){
                int x = curr.second.first + dirs[i];
                int y = curr.second.second + dirs[i+1];
                int count = 0;
                while(0<=x && 0<=y && x<m && y<n && maze[x][y]==0){
                    x += dirs[i];
                    y += dirs[i+1];
                    count++;
                }
                if(distance[curr.second.first][curr.second.second] + count < distance[x-dirs[i]][y-dirs[i+1]]){
                    distance[x-dirs[i]][y-dirs[i+1]] = distance[curr.second.first][curr.second.second] + count;
                    pq.push({distance[x-dirs[i]][y-dirs[i+1]],{x-dirs[i],y-dirs[i+1]}});
                }
            }
        }
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        distance[start[0]][start[1]] = 0;
        dijkstra(maze,start,distance);
        return (distance[destination[0]][destination[1]]==INT_MAX? -1 : distance[destination[0]][destination[1]]);
    }
};