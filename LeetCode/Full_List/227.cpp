class Solution {
public:
    
    int calculate(int a, int b, char c){
        if(c=='+')
            return a+b;
        if(c=='-')
            return a-b;
        if(c=='*')
            return a*b;
        return a/b;
    }
    
    int calculate(string s) {
        unordered_map<char,int> precedence;
        precedence['+'] = 0;precedence['-'] = 0;
        precedence['/'] = 1;precedence['*'] = 1;
        stack<int> digits;
        digits.push(0);
        stack<char> sign;
        int n = s.size();
        string nums = "";
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                nums += s[i];
                continue;
            }
            if(nums.size()!=0){
                digits.push(stoi(nums));
                nums = "";
            }
            if(s[i]!=' '){
                while(!sign.empty() && precedence[sign.top()]>=precedence[s[i]]){
                    int b = digits.top();digits.pop();
                    int a = digits.top();digits.pop();
                    int c = calculate(a,b,sign.top());
                    digits.push(c);
                    sign.pop();
                    
                }
                sign.push(s[i]);
            }
        }
        if(nums.size()!=0)
            digits.push(stoi(nums));
        while(!sign.empty()){
            int b = digits.top();digits.pop();
            int a = digits.top();digits.pop();
            int c = calculate(a,b,sign.top());
            digits.push(c);
            sign.pop();
        }
        return digits.top();
    }
};