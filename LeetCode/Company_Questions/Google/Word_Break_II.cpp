class Solution {
public:
    unordered_map<string,vector<string>> ump;
    vector<string> recursive(string s, unordered_set<string>& ust){
        if(ump.count(s))
            return ump[s];
        vector<string> res;
        if(ust.count(s))
            res.push_back(s);
        for(int i=s.size()-1; i>0; i--){
            string last_word = s.substr(i);
            if(ust.count(last_word)){
                vector<string> prefix = recursive(s.substr(0,i),ust);
                for(int i=0; i<prefix.size(); i++)
                    prefix[i] += " "+last_word;
                res.insert(res.end(),prefix.begin(),prefix.end());
            }
        }
        ump[s] = res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(),wordDict.end());
        return recursive(s,ust);
    }
};