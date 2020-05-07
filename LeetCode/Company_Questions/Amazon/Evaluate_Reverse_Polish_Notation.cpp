class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a,b;
        for(auto elem: tokens){
            if(elem == "+"){
                a = s.top();s.pop();
                b = s.top();s.pop();
                s.push(a+b);
            }
            else if(elem == "-"){
                a = s.top();s.pop();
                b = s.top();s.pop();
                s.push(b-a);
            }
            else if(elem == "*"){
                a = s.top();s.pop();
                b = s.top();s.pop();
                s.push(b*a);
            }
            else if(elem == "/"){
                a = s.top();s.pop();
                b = s.top();s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoi(elem));
            }
        }
        return s.top();
    }
};