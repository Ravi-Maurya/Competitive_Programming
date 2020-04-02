int area(vector<int> A){
    int n = A.size();
    stack<int> s;
    int top,i=0,currarea=0,maxarea=0;
    while(i<n){
        if(s.empty() || A[s.top()]<=A[i])
            s.push(i++);
        else{
            top = A[s.top()];
            s.pop();
            currarea = top*i;
            if(!s.empty())
                currarea = top*(i-s.top()-1);
            maxarea = max(maxarea,currarea);
        }
    }
    while(!s.empty()){
        top = A[s.top()];
        s.pop();
        currarea = top*i;
        if(!s.empty())
            currarea = top*(i - s.top() - 1);
        maxarea = max(maxarea,currarea);
    }
    return maxarea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int res = area(A[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++)
            if(A[i][j]!=0)
                A[i][j] += A[i-1][j];
        res = max(res,area(A[i]));
    }
    return res;
}
