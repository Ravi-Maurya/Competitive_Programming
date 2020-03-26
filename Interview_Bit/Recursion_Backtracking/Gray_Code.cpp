vector<int> solve(vector<int> &t,int i){
    vector<int> tmp = t;
    reverse(tmp.begin(),tmp.end());
    for(auto s: tmp){
        t.push_back(s+pow(2,i));
    }
    return t;
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> res;
    if (A==0)
        return res;
    res.push_back(0);
    res.push_back(1);
    if (A==1)
        return res;
    for(int i=1;i<A;i++)
        res = solve(res,i);
    return res;
}
