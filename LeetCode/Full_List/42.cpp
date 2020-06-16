class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)
            return 0;
        int n = height.size();
        vector<int> right(n);
        right[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            right[n-1-i] = max(right[n-i],height[n-i-1]);
        }
        int left_max = height[0];
        int res = min(left_max,right[0]) - height[0];
        for(int i=1; i<n; i++){
            left_max = max(left_max,height[i]);
            res  +=  min(left_max,right[i]) - height[i];
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0, curr = 0;
        while(curr<height.size()){
            while(!st.empty() && height[st.top()]<height[curr]){
                int top = st.top();st.pop();
                if(st.empty())
                    break;
                int breadth = curr - st.top() - 1;
                int length = min(height[curr],height[st.top()]) - height[top];
                res += breadth*length;
            }
            st.push(curr++);
        }
        return res;
    }
};