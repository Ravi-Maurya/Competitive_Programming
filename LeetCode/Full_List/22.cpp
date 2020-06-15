class Solution {
public:
    void recursive(vector<string>& res, string curr, int open, int close , int n){
        
        if(curr.size() == 2*n){
            res.push_back(curr);
            return;
        }
        if(open<n)
            recursive(res, curr+"(", open+1, close, n);
        if(close<open)
            recursive(res, curr+")", open, close+1, n);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursive(res,"",0,0,n);
        return res;
    }
};