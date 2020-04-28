class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> count_t(26,0);
        for(auto ch: T){
            count_t[ch-'a']++;
        }
        string res = "";
        for(int i=0; i<S.size();i++){
            int count = count_t[S[i]-'a'];
            count_t[S[i]-'a'] = 0;
            while(count--)
                res += S[i];
        }
        for(int i=0;i<26;i++){
            int count = count_t[i];
            while(count--){
                res += (char)(i+'a');
            }
        }
        return res;
    }
};