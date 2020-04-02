int Max(int a, int b, int c, int d, int e) {
    return max(max(max(a, b), max(c, d)), e);
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int rows = B.size();
    int cols = B[0].size();

    int max_dist = A;
    vector<vector<int>> curr_dist = B;
    vector<vector<int>> next_dist = curr_dist;

    for (int dist = 0; dist < max_dist; dist++) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int cur = curr_dist[r][c];
                int right = (c == cols - 1) ? -1 : curr_dist[r][c + 1];
                int up = (r == 0) ? -1 : curr_dist[r - 1][c];
                int left = (c == 0) ? -1 : curr_dist[r][c - 1];
                int down = (r == rows - 1) ? -1 : curr_dist[r + 1][c];
                next_dist[r][c] = Max(cur, right, up, left, down);
            }
        }

        curr_dist = next_dist;
    }
    return curr_dist;
}