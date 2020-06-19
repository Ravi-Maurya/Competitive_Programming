class Solution {
public:
    unordered_map<string, vector<string>> dp;
    vector<string> rec(const string s, const unordered_set<string>& wordDict){
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        vector<string> ans;
        if(wordDict.find(s) != wordDict.end()){
            ans.push_back(s);
        }
        for(int i = s.length() - 1;i > 0; --i){
            string last = s.substr(i,s.length() - i);
            if(wordDict.find(last) != wordDict.end()){
                vector<string> pre = rec(s.substr(0, i), wordDict);
                for(int i = 0;i < pre.size(); ++i){
                    pre[i] += " " + last;
                }
                ans.insert(ans.end(), pre.begin(), pre.end());
            }
        }
        dp[s] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return rec(s, dict);
    }
};