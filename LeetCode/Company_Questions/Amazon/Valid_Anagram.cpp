class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> check(26,0);
        for(auto ch: s){
            check[ch-'a']++;
        }
        for(auto ch: t){
            check[ch-'a']--;
        }
        for(int i=0; i<26; i++)
            if(check[i]!=0)
                return false;
        return true;
    }
};