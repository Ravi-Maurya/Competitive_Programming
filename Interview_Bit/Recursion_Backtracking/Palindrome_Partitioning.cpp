bool isPal(string s){
    int n = s.size();
    for(int i=0;i<=n/2;i++)
        if(s[i]!=s[n-1-i])
            return false;
    return true;
}

void recursive(vector<vector<string>> &res, int idx, string A, vector<string> &tmp){
    if(idx==A.size())
        res.push_back(tmp);
    else{
        for(int i=idx;i<A.size();i++){
            string t = A.substr(idx,i+1-idx); 
            if (isPal(t)){
                tmp.push_back(t);
                recursive(res,i+1,A,tmp);
                tmp.pop_back();
            }
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> res;
    vector<string> tmp;
    recursive(res,0,A,tmp);
    return res;
    
}
