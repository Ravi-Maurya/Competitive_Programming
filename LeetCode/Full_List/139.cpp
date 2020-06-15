class Solution {
public:
    vector<int> dp;
    bool recursive(string s, unordered_set<string>& ust, int idx, int n){
        if(idx>=n)
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        for(int i = idx; i<n; i++){
            string tmp = s.substr(idx,i-idx+1);
            if(ust.count(tmp) && recursive(s,ust,i+1,n)){
                dp[i+1] = 1;
                return true;
            }
        }
        dp[idx] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(), wordDict.end());
        int n = s.size();
        dp.resize(n+1,-1);
        return recursive(s,ust,0,n);
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 0;i<s.size();i++){
            if(dp[i]){
                for(auto& j: wordDict){
                    if(s.substr(i, j.size())==j){
                        dp[i+j.size()] = true;
                    }
                }
            }
        }
        return dp.back();
    }
};