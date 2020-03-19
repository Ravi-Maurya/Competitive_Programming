vector<int> Solution::getRow(int A) {
    vector <int> res;
    vector <int> tmp;
    res.push_back(1);
    if (A==0)
        return res;
    res.push_back(1);
    if (A==1)
        return res;
    int k = 2,t,i;
    while (k<=A){
        tmp.push_back(1);
        t = res.size();
        for (i=1;i<t;i++)
            tmp.push_back(res[i]+res[i-1]);
        tmp.push_back(1);
        res.clear();
        res = tmp;
        tmp.clear();
        k++;
    }
    return res;
}
