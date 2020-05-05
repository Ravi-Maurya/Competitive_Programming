class Solution {
public:
    bool wordBreak(string A, vector<string>& B) {
    unordered_set<string> s(B.begin(), B.end());
    int n = A.size();
    vector<int> tmp(n+1,0);
    tmp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            string t = A.substr(i, j-i+1);
            if(s.find(t)!=s.end() && tmp[j+1] == 1){
                tmp[i] = 1;
                break;
            }
        }
    }
    return tmp[0];
    }
};

class Solution2 {
public:
    bool recursive(string s, unordered_set<string>& ust){
        int size = s.size();
        if(size==0)
            return true;
        bool dp[size+1];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=size; i++){
            if(!dp[i] && (ust.find(s.substr(0,i))!=ust.end()))
                dp[i] = true;
            if(dp[i]){
                if(i==size)
                    return true;
                for(int j=i+1; j<=size; j++){
                    if(!dp[j] && (ust.find(s.substr(i,j-i))!=ust.end()))
                        dp[j] = true;
                    if(j==size && dp[j])
                        return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(), wordDict.end());
        return recursive(s,ust);
    }
};