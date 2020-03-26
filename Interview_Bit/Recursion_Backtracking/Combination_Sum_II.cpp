void recursive(set <vector<int>> &res, vector<int> &A, vector<int> &tmp, int idx, int remaining){
    if(remaining<0)
        return;
    if(remaining==0){
        if(res.find(tmp)==res.end())
            res.insert(tmp);
        return;
    }
    if(idx>=A.size())
        return;
    tmp.push_back(A[idx]);
    recursive(res,A,tmp,idx+1,remaining-A[idx]);
    tmp.pop_back();
    recursive(res,A,tmp,idx+1,remaining);
    return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> res;
    vector<int> tmp;
    set <vector<int>> s;
    sort(A.begin(),A.end());
    recursive(s,A,tmp,0,B);
    for(auto x: s){
        res.push_back(x);
    }
    return res;
}
