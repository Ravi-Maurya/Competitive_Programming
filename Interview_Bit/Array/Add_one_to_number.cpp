vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size(),i;
    i = 0;
    while (i<n && A[i]==0) i++;
    vector <int> res;
    if (i==n){
        res.push_back(1);
        return res;
    }
    for(int j=i;j<n;j++)
        res.push_back(A[j]);
    n = res.size();
    res[n-1] += 1;
    for(i=n-1;i>0;i--){
        if (res[i]<10)
            return res;
        res[i-1] += 1;
        res[i] = 0;
    }
    if (res[0]<10) return res;
    res[0] = 0;
    res.insert(res.begin(),1);
    return res;
}