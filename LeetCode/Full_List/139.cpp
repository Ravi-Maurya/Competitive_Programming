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
                dp[idx] = 1;
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


class Solution {// S = s1 + s2 if(s1 and s2 int wordDict then S is also in wordDict)
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;        
        for(int length = 1; length<=n; length++){
            for(int i=0; i<length;i++){
                if(dp[i] && ust.count(s.substr(i,length-i))){
                    dp[length] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};


class Solution {// O(nk)
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 0;i<s.size();i++){
            if(dp[i]){
                for(auto& j: wordDict){
                    if(!dp[i+j.size()] && s.substr(i, j.size())==j){
                        dp[i+j.size()] = true;
                    }
                }
            }
        }
        return dp.back();
    }
};


class Solution {//BFS O(n2) o(n);
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(),wordDict.end());
        vector<bool> visited(s.size(),0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int start = q.front();q.pop();
            if(!visited[start]){
                for(int en = start +1; en<=s.size(); en++){
                    if(ust.count(s.substr(start,en-start))){
                        q.push(en);
                        if(en == s.size())
                            return true;
                    }
                }
                visited[start] = 1;
            }
        }
        return false;
    }
};