class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())
            return false;
        int i = 0, n = s.size();
        for(int j=0;j<t.size();j++){
            if(i<n){
                if(t[j]==s[i])
                    i++;
            }
            else{
                return true;
            }
        }
        return (i>=n);
    }
};