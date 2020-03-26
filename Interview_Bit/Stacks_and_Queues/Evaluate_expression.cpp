int Solution::evalRPN(vector<string> &A) {
    stack<int> num;
    int n = A.size();
    for(int i=0;i<n;i++){
        int a,b;
        if(A[i]=="+"){
            b = num.top();
            num.pop();
            a = num.top();
            num.pop();
            num.push(a+b);
        }
        else if(A[i]=="-"){
            b = num.top();
            num.pop();
            a = num.top();
            num.pop();
            num.push(a-b);
        }
        else if(A[i]=="*"){
            b = num.top();
            num.pop();
            a = num.top();
            num.pop();
            num.push(a*b);
        }
        else if(A[i]=="/"){
            b = num.top();
            num.pop();
            a = num.top();
            num.pop();
            num.push(a/b);
        }
        else{
            num.push(stoi(A[i]));
        }
    }
    return num.top();
}
