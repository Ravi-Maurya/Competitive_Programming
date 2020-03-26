void recursive(vector<vector<int>> &res, int n, int k, vector<int> &tmp, int val){
    if (k==0){
        res.push_back(tmp);
        return;
    }
    if (val>n)
        return;
    tmp.push_back(val);
    recursive(res,n,k-1,tmp,val+1);
    tmp.pop_back();
    recursive(res,n,k,tmp,val+1);
    return;
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> res;
    if(B>A)
        return res;
    vector<int> tmp;
    recursive(res,A,B,tmp,1);
    return res;
}
