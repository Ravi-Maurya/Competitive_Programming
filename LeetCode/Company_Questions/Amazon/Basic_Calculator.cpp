class Solution {
public:
    int calculate(string s) {
        stack<int> stck;
        int operand = 0, res = 0, sign = 1, n=  s.size();
        for(int i=0; i<n; i++){
            auto ch = s[i];
            if(isdigit(ch)){
                operand = 10*operand + (int)(ch-'0');
            }
            else if(ch == '+'){
                res += sign*operand;
                sign = 1;
                operand = 0;
            }
            else if(ch=='-'){
                res += sign*operand;
                sign = -1;
                operand = 0;
            }
            else if(ch  == '('){
                stck.push(res);
                stck.push(sign);
                sign = 1;
                res = 0;
            }
            else if(ch  == ')'){
                res += sign*operand;
                res *= stck.top();
                stck.pop();
                res += stck.top();
                stck.pop();
                operand = 0;
            }
        }
        return res+(sign*operand);
    }
};