int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size(),i;
    stack<int> st;
    int res = 0,top,area;
    while(i<n){
        if(st.empty() || A[st.top()]<=A[i]){
            st.push(i);
            i++;
        }
        else{
            top = st.top();
            st.pop();
            area = A[top]*(st.empty() ? i: i-1-st.top());
            res = max(res,area);
        }
    }
    while(!st.empty()){
        top = st.top();
        st.pop();
        area = A[top]*(st.empty() ? i: i-1-st.top());
        res = max(res,area);
    }
    return res;
}
