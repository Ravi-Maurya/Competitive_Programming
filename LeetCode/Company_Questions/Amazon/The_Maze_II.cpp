#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void dijkstra(vector<vector<int>>& maze, vector<int>& start, vector<vector<int>>& distance){
        vector<int> dirs = {-1,0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{start[0],start[1]}});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(distance[curr.second.first][curr.second.second]<curr.first)
                continue;
            for(int i=0; i<4; i++){
                int nr = curr.second.first + dirs[i];
                int nc = curr.second.second + dirs[i+1];
                int count = 0;
                while(0<=nr && 0<=nc && nr<m && nc<n && maze[nr][nc]==0)
                    nr += dirs[i], nc += dirs[i+1], count++;
                nr -= dirs[i], nc -= dirs[i+1];
                if(distance[curr.second.first][curr.second.second] + count <distance[nr][nc]){
                    distance[nr][nc] = distance[curr.second.first][curr.second.second] + count;
                    pq.push({distance[nr][nc],{nr,nc}});
                }
            }
        }
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        distance[start[0]][start[1]] = 0;
        dijkstra(maze, start, distance);
        int res = distance[destination[0]][destination[1]];
        return res==INT_MAX ? -1:res;
    }
}