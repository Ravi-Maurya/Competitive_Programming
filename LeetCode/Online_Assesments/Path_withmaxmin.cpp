#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        vector<vector<int>> dir {{0,1},{1,0},{0,-1},{-1,0}};
        // value < row, col> 
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({A[0][0], {0, 0}});
        int r = A.size();
        int c = A[0].size();
        int res = A[0][0];
        A[0][0] = -1; //set it as visited
        while(!pq.empty()) {
            auto m = pq.top();
            pq.pop();
            res = min(res, m.first);
            if(m.second.first == r-1 && m.second.second == c-1) return res;
            for(auto d: dir) {
                int i = m.second.first + d[0];
                int j = m.second.second + d[1];
                if(i >= 0 && i < r && j >= 0 && j < c && A[i][j] != -1) { //check
                    pq.push({A[i][j], {i,j}});
                    A[i][j] = -1;
                } 
            }
        }
        return -1; // shouldn't get here
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}