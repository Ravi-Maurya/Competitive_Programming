class Solution {
    bool compares(unordered_map<char,int>& pat, unordered_map<char,int>& txt){
        for(auto it = txt.begin(); it!=txt.end(); it++)
            if(!(pat.count(it->first) && it->second==pat[it->first]))
                return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int window = p.size();
        int n = s.size();
        if(n<window)
            return {};
        unordered_map<char,int> pat,tmp;
        for(auto ch: p)
            pat[ch]++;
        vector<int> res;
        for(int i=0; i<window; i++)
            tmp[s[i]]++;
        if(compares(pat,tmp))
            res.push_back(0);
        for(int j = window; j<n; j++){
            int start = j-window+1;
            tmp[s[start-1]]--;
            tmp[s[j]]++;
            if(tmp[s[start-1]]==0)
                tmp.erase(s[start-1]);
            if(compares(pat,tmp))
                res.push_back(start);
        }
        return res;
    }
};