class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return vector<int>();
        return helper(input, 0, input.size() -1);
    }
    
    vector<int> helper(string& input, int startIdx, int endIdx) {
        vector<int> result;
        for (int i = startIdx; i < endIdx; i++) {
            if (input[i] =='+'|| input[i] == '-' || input[i] == '*') {
                vector<int> left = helper(input, startIdx, i-1);
                vector<int> right = helper(input, i+1, endIdx);
                for (int val1 : left) {
                    for (int val2 : right) {
                        switch(input[i]) {
                            case '+': result.push_back(val1 + val2); break;
                            case '-': result.push_back(val1 - val2); break;
                            case '*': result.push_back(val1 * val2); break;
                        }
                    }
                }
            }
        }
        if (result.empty()){
            int operand = 0;
            int i = startIdx;
            while(i < input.size() && isdigit(input[i])) {
                operand = 10 * operand + (input[i]-'0');
                i++;
            }
            result.push_back(operand);
        }
        return result;
    }
};