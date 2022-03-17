int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    vector<vector<int>> sum_arr(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum_arr[i][j] = sum_arr[i][j-1] + A[i-1][j-1];
        }
        for(int j=1; j<=n; j++){
            sum_arr[i][j] = sum_arr[i][j] + sum_arr[i-1][j];
            // cout<<i << " || " << j << " || " << sum_arr[i][j] << "\n";
        }
    }
    int ans = INT_MIN;
    for(int i=B; i<=n; i++){
        for(int j=B; j<=n;j++){
            ans = max(ans, sum_arr[i][j] + sum_arr[i-B][j-B] - sum_arr[i][j-B] - sum_arr[i-B][j]);
        }
    }
    return ans;

}
