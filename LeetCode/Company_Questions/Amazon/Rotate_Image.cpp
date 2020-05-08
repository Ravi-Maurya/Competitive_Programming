class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        int n = A.size();
        for (int x=0;x<n/2;x++){
            for(int y=x;y<n-x-1;y++){
                int tmp = A[x][y];
                A[x][y] = A[n-1-y][x];
                A[n-1-y][x] = A[n-1-x][n-1-y];
                A[n-1-x][n-1-y] = A[y][n-1-x];
                A[y][n-1-x] = tmp;
            }
        }
        return;
    }
};