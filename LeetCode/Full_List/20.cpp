class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(auto ch: s){
            cout<<ch<<" "<<stck.size()<<"\n";
            if(ch=='{' || ch=='[' || ch=='(')
                stck.push(ch);
            else if(!stck.empty()){
                char top = stck.top();
                if((ch=='}' && top=='{') || (ch==']' && top=='[') || (ch==')' && top=='('))
                    stck.pop();
                else
                    return false;
            }
            else
                return false;
        }
        return stck.empty();
    }
};