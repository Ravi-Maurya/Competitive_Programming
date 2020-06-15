class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ump;
        int i = 0, j = 0, n = s.size(), res = 0;
        while(j<n){
            if(ump.count(s[j]))
                if(i<=ump[s[j]])
                    i = ump[s[j]] + 1;
            ump[s[j]] = j;
            j++;
            res = max(res,j-i);
        }
        return res;
    }
};