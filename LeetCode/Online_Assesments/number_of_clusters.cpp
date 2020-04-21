#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '2'; // Visisted so mark to '2'
        if (row-1 >= 0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
        if (col-1 >= 0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
        if (row+1 < grid.size() && grid[row+1][col] == '1') dfs(grid, row+1, col);
        if (col+1 < grid[0].size() && grid[row][col+1] == '1') dfs(grid, row, col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') { // Found a land, find the region by recursion
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}