vector<vector<int> > Solution::solve(int A) {
    vector <vector<int>> res;
    vector <int> tmp;
    if (A==0)
     return res;
    res.push_back({1});
    if (A==1)
        return res;
    res.push_back({1,1});
    if (A==2)
        return res;
    int k = 3,t,i;
    while (k<=A){
        tmp.push_back(1);
        t = res[k-2].size();
        for (i=1;i<t;i++)
            tmp.push_back(res[k-2][i]+res[k-2][i-1]);
        tmp.push_back(1);
        res.push_back(tmp);
        tmp.clear();
        k++;
    }
    return res;
}
