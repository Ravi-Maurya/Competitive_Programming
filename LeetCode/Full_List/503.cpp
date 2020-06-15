class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return {};
        if(n==1)
            return {-1};
        vector<int> res(n,-1);
        stack<int> st;
        int j = n-1;
        int maxval = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]>maxval){
                maxval = nums[i];
                j = i;
            }
        }
        int i = (j+1)%n;
        st.push(i);
        i = (i+1)%n;
        for(; i!=(j+1)%n; i = (i+1)%n){
            // cout<< i <<"\n";
            while(!st.empty() && nums[st.top()]<nums[i]){
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};