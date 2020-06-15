class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
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
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0)
            return 0;
        if(n==1)
            return heights[0];
        heights.push_back(0);
        stack<int> st;
        st.push(-1);
        int res = 0, curr, top;
        for(int i=0; i<=n; i++){
            while(st.top()!=-1 && heights[st.top()]>heights[i]){
                top = st.top();st.pop();
                curr = heights[top]*(i-st.top()-1);
                if(res<curr)
                    res = curr;
            }
            st.push(i);
        }
        return res;
    }
};