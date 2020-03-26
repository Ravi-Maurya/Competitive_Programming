int Solution::isValid(string A) {
    int n = A.size();
    int i=0;
    stack<char> openbrackets;
    for(i=0;i<n;i++){
        if(A[i]=='{' || A[i]=='(' || A[i]=='[')
            openbrackets.push(A[i]);
        else if (!openbrackets.empty() && ((A[i]=='}' && openbrackets.top()=='{')||(A[i]==']' && openbrackets.top()=='[')||(A[i]==')' && openbrackets.top()=='(')))
            openbrackets.pop();
        else
            return 0;
    }
    if(openbrackets.empty())
        return 1;
    return 0;
}
