class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ump;
        int n = s.size();
        int ans = 0, i, j;
        for(j=0,i=0;j<n;j++){
            if(ump.count(s[j]))
                i = max(i,ump[s[j]]);
            ans = max(ans, j-i+1);
            ump[s[j]] = j+1;
        }
        return ans;
    }
};