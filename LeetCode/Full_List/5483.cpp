class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(abs(s[i]-st.top())==32)
                st.pop();
            else
                st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
            res += st.top();st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};