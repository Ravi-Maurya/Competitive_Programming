class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> arr(26,0);
        for(auto ch: s)
            arr[ch-'a']++;
        for(auto ch: t)
            arr[ch-'a']--;
        for(auto x:arr)
            if(x!=0)
                return false;
        return true;
    }
};