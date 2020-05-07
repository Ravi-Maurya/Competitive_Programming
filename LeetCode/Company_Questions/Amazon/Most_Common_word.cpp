class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph += '.';
        unordered_set<string> ust(banned.begin(), banned.end());
        unordered_map<string,int> ump;
        string ans = "";
        int ans_freq = 0;
        string word = "";
        for(auto ch: paragraph){
            if(isalpha(ch))
                word += tolower(ch);
            else if(word.size()>0){
                string final_word = word;
                if(ust.find(final_word)==ust.end()){
                    ump[final_word]++;
                    if(ump[final_word]>ans_freq){
                        ans = final_word;
                        ans_freq = ump[final_word];
                    }
                }
                word = "";
            }
        }
        return ans;
    }
};