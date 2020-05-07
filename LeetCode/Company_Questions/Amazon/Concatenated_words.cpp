class Solution {
    bool canBuild(string const& s, const unordered_set<string_view>& prev) {
        if (prev.size() == 0) return false;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (size_t i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j)
                if (dp[j] &&
                    prev.count(string_view(s.c_str()+j, i - j))) {
                    dp[i] = true;
                    break;
                }
        }
        return dp[s.size()];
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const string& l, const string& r) -> bool { return l.size() < r.size();});
        vector<string> res;
        unordered_set<string_view> previous;
        previous.reserve(words.size());
        for (string& s : words) {
            if (canBuild(s, previous))
                res.emplace_back(s);
            previous.insert(string_view(s.c_str(), s.size()));
        }
        return res;
    }
};