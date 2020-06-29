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


class Solution {
    /*
    The idea is to choose the first word occuring int the string and recursively generate the other part
    to do so we check if every word in the worDict is the first word if yes then recursively calculate the other part
    */
public:
    
    unordered_map<string,vector<string>> dp;
    
    vector<string> helper(string s, vector<string>& wordDict){
        vector<string> res;
        if(s.size()==0){
            res.push_back("");
            return res;
        }
        if(dp.count(s))
            return dp[s];
        for(auto word: wordDict){
            if(s.size()>=word.size() && s.substr(0,word.size())==word){
                string sub = s.substr(word.size());
                auto substrings = helper(sub,wordDict);
                for(auto substring: substrings){
                    string space = ((substring.size()==0)?"":" ");
                    res.push_back(word + space + substring);
                }
            }
        }
        dp[s] = res;
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return helper(s,wordDict);
    }
};

class Solution {
    /*
    same idea as above just optimizing the string length only
    100% results
    */
public:
    unordered_map<int,vector<string>> dp;
    unordered_set<string> dic;
    int maxlength = INT_MIN;
    vector<string> helper(string& s, int start){
        if(start >= s.size())return {};
        if(dp.count(start))
            return dp[start];
        vector<string> res;
        for(int i=start; i<start+maxlength && i<s.size(); i++){
            string sub = s.substr(start, i-start+1);
            if(dic.find(sub) != dic.end()){
                vector<string> tmp = helper(s, i+1);
                if(i+1 >= s.size()){
                    res.push_back(sub);
                }
                for(int j=0; j<tmp.size(); j++){
                    res.push_back(sub+" "+tmp[j]);
                }
            }
        }
        dp[start] = res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size(); i++){
            dic.insert(wordDict[i]);
            int tmp = wordDict[i].size();
            maxlength = max(maxlength, tmp);
        }
        return helper(s,0);
    }
};