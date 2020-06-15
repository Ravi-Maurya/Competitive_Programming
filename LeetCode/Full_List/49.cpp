class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> ump;
        for(auto s: strs){
            vector<int> tmp(26,0);
            for(auto ch: s){
                tmp[ch-'a']++;
            }
            ump[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it=ump.begin(); it!=ump.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};