void recursive(vector<string> &res, int left, int right, string tmp){
    if(left>0){
        string t = tmp+"(";
        recursive(res,left-1,right,t);
        
    }
    if(left<right){
        string t = tmp+")";
        recursive(res,left,right-1,t);
    }
    if(right==0)
        res.push_back(tmp);
    return;
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> res;
    string tmp = "";
    recursive(res,A,A,tmp);
    return res;
}
