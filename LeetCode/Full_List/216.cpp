class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n);
};
void recursive(set <vector<int>> &res, vector<int> &A, vector<int> &tmp, int idx, int remaining, int k){
    if(remaining<0)
        return;
    if(remaining==0 && k==0){
        if(res.find(tmp)==res.end())
            res.insert(tmp);
        return;
    }
    if(idx>=A.size() || k<0)
        return;
    tmp.push_back(A[idx]);
    recursive(res,A,tmp,idx+1,remaining-A[idx],k-1);
    tmp.pop_back();
    recursive(res,A,tmp,idx+1,remaining,k);
    return;
}

vector<vector<int> > Solution::combinationSum3(int k, int B) {
    vector<int> A = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> res;
    vector<int> tmp;
    set <vector<int>> s;
    sort(A.begin(),A.end());
    recursive(s,A,tmp,0,B,k);
    for(auto x: s){
        res.push_back(x);
    }
    return res;
}
