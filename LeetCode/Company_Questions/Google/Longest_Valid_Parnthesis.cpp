class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stck;
        int res = 0;
        stck.push(-1);
        for(int i=0; i<s.size(); i++){
            auto ch = s[i];
            if(ch == '(')
                stck.push(i);
            else{
                stck.pop();
                if(stck.empty())
                    stck.push(i);
                else
                    res = max(res,i-stck.top());
            }
        }
        return res;
    }
};