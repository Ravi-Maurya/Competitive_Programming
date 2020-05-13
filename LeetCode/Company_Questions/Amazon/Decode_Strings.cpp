class Solution {
public:
    string decodeString(string s) {
        stack<int> st; 
        string ans = "";
        int n = 0;
        for (auto ch : s) {
            if (isdigit(ch)) {
                n = (n * 10) + (int(ch) - int('0'));
            } 
            else if (ch == '[') { 
                st.push(n);
                n = 0;
                st.push(ans.length()); 
            } 
            else if (ch == ']') {
                int left = st.top(); st.pop();
                int rep = st.top() - 1; st.pop();
                while (rep > 0) {
                    int len = ans.length();
                    while (left < len) { ans += ans[left]; left++; }
                    rep--;
                }
            } 
            else {
                ans += ch;
            }

        }
        
        return ans;
    }
};