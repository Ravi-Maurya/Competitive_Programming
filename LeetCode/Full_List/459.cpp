class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> kmp(n+1,0);
        for(int j=0, i=1; i<s.size();){
            if(s[i]==s[j])
                kmp[++i] = ++j;
            else if(j==0)
                i++;
            else
                j = kmp[j];
        }
        return (kmp[n]!=0 && (kmp[n]%(n - kmp[n])==0));
    }
};