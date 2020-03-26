int Solution::braces(string A) {
    stack<char> s;
    int n = A.size();
    int i = 0;
    string tmp="";
    for(i=0;i<n;i++){
        if(A[i]==' ')
            continue;
        else if(A[i]==')'){
            int count = 0;
            while(!s.empty() && s.top()!='('){
                count++;
                s.pop();
            }
            if (count<=1)
                return 1;
            if(!s.empty()){
                s.pop();
                s.push('#');
            }
        }
        else
            s.push(A[i]);
    }
    return 0;
}
