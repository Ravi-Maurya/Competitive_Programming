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


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<int> height(n,0),left(n,0),right(n,n);
        for(int i=0; i<m; i++){
            int curr_left = 0, curr_right = n;
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                    left[j] = max(left[j],curr_left);
                }
                else{
                    height[j] = 0;
                    left[j] = 0;
                    curr_left = j+1;
                }
                
                int jr = n-j-1;
                if(matrix[i][jr]=='1')
                    right[jr] = min(right[jr],curr_right);
                else{
                    right[jr] = n;
                    curr_right = jr;
                }
            }
            
            for(int j=0; j<n; j++){
                res = max(res, (right[j]-left[j])*height[j]);
            }
        }
        return res;
    }
};