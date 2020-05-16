class Solution {
public:
    string removeOuterParentheses(string S) {
        int left = 1, right = 0;
        string res = "";
        int n = S.size();
        for(int j = 1; j<n; j++){
            int i = j - left - right;
            if(S[j]=='(')
                left++;
            else
                right++;
            if(left==right){
                if(i+1!=j)
                    res += S.substr(i+1,j-i-1);
                left = 0;
                right = 0;
            }
        }
        return res;
    }
};