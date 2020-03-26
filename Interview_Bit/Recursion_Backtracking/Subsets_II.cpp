void recursive(vector<vector<int>> &res, vector<int> &A, vector<int> &tmp, int idx){
    if(idx>=A.size()){
        res.push_back(tmp);
        return;
    }
    int nxt = idx+1;
    while (nxt<A.size() && A[nxt]==A[idx])
        nxt++;
    for(int i=0;i<nxt-idx+1;i++){
        for(int j=0;j<i;j++)
            tmp.push_back(A[idx]);
        recursive(res,A,tmp,nxt);
        for(int j=0;j<i;j++)
            tmp.pop_back();
    }
    return;
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(A.begin(),A.end());
    recursive(res,A,tmp,0);
    sort(res.begin(),res.end());
    return res;
}
