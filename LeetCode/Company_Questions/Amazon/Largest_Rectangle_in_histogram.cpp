class Solution {
public:
    int largestRectangleArea(vector<int>& heights);
};
int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size(),i;
    stack<int> st;
    int res = 0,top,area;
    for(i=0; i<n; i++){
        if(st.empty() || A[st.top()]<=A[i]){
            st.push(i);
            continue;
        }
        while(!st.empty() && A[i]<A[st.top()]){
            top = st.top();
            st.pop();
            area = A[top]*(st.empty() ? i: i-1-st.top());
            res = max(res,area);
        }
        st.push(i);
    }
    while(!st.empty()){
        top = st.top();
        st.pop();
        area = A[top]*(st.empty() ? i: i-1-st.top());
        res = max(res,area);
    }
    return res;
}
