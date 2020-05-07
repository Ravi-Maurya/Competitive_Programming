class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        int n = s.size();
        for(int i=0; i<n; i++){
            auto ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{')
                stck.push(ch);
            else{
                if(!stck.empty() && ((ch==')' && stck.top()=='(') || (ch=='}' && stck.top()=='{') || (ch==']' && stck.top()=='[')))
                    stck.pop();
                else
                    return false;
            }
        }
        return stck.empty();
    }
};