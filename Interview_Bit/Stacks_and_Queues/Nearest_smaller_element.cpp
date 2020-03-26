vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> st;
    vector<int> res;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=A[i])
            st.pop();
        if(!st.empty())
            res.push_back(st.top());
        else
            res.push_back(-1);
        st.push(A[i]);
    }
    return res;
}
