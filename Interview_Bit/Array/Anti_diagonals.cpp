vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> res(2*n-1);
    int row = 0;
    for(int i=0;i<n;i++){
        int r = 0, c = i;
        while (r<n && c>=0){
            res[row].push_back(A[r][c]);
            r++;
            c--;
        }
        row++;
    }
    for(int i=1;i<n;i++){
        int r = i, c = n-1;
        while (r<n && c>=0){
            res[row].push_back(A[r][c]);
            r++;
            c--;
        }
        row++;
    }
    return res;
}
