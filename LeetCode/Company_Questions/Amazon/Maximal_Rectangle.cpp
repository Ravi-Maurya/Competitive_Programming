class Solution {
public:
    int largestRectangleArea(vector<int>& A);
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int n = matrix.size();
        if(n==0)
            return res;
        int m = matrix[0].size();
        if(m==0)
            return res;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }
            res = max(res,largestRectangleArea(heights));
        }
        return res;
    }
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
