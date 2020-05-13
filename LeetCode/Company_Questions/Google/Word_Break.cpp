class Solution {
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