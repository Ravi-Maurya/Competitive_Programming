#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int maxScore(vector<vector<int> >& grid){
    if (grid.empty())
        return 0;
    for (unsigned int i = 1; i < grid[0].size(); i++)
        grid[0][i] = min(grid[0][i], grid[0][i-1]);
    for (unsigned int i = 1; i < grid.size(); i++)
        grid[i][0] = min(grid[i][0], grid[i-1][0]);
    for (unsigned int i = 1; i < grid.size(); i++){
        for (unsigned int j = 1; j < grid[0].size(); j++){
            grid[i][j] = max(min(grid[i-1][j], grid[i][j]),min(grid[i][j-1], grid[i][j]));
        }
    }
    return grid[grid.size()-1][grid[0].size()-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}