class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size(),top,res=0,curr;
        vector<int> heights(n+1,0);
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            stack<int> st;
            st.push(-1);
            for(int j=0; j<=n; j++){
                while(st.top()!=-1 && heights[st.top()]>heights[j]){
                    top = st.top();st.pop();
                    curr = heights[top]*(j-st.top()-1);
                    if(res<curr)
                        res = curr;
                }
                st.push(j);
            }
        }
        return res;
    }
};