class Solution {
public:
    
    bool check(string& a, string& b){
        if(a.size() + 1 != b.size())
            return false;
        int count[26];
        memset(count,0,sizeof(count));
        for(auto x: b)
            ++count[x-'a'];
        for(auto x: a){
            --count[x-'a'];
            if(count[x-'a']<0)
                return false;
        }
        int res = 0;
        for(int i=0; i<26;i++){
            if(count[i]!=0)
                res += count[i];
        }
        return (res==1);
    }
    
    static bool compare(string &a, string &b){
        if(a.size()<b.size())
            return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> dp(n,1);
        int res = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(words[j],words[i]) && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1;
                
            }
            if(res<dp[i])
                res = dp[i];
        }
        return res;
    }
};