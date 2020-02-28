vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> res;
    if (A==0)
        return res;
    vector<int> row;
    row.push_back(1);
    res.push_back(row);
    for(int i=1;i<A;i++){
        row.clear();
        row.push_back(1);
        for(int j=1;j<i;j++)
            row.push_back(res[i-1][j-1]+res[i-1][j]);
        row.push_back(1);
        res.push_back(row);
    }
    return res;
}
