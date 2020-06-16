class Solution {
public:
    bool check(unordered_map<string,int>& ump, unordered_map<string,int>& tmp){
        for(auto& [w,val]:ump){
            if(!tmp.count(w) || tmp[w]!=val)
                return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int number_of_words = words.size();
        if(number_of_words==0)
            return {};
        int wordsize = words[0].size();
        if(wordsize==0)
            return {};
        int total_size_of_word = wordsize*number_of_words;
        int string_size = s.size();
        if(total_size_of_word>string_size)
            return {};
        unordered_map<string,int> ump,ump2;
        for(auto& word: words)
            ump[word]++;
        vector<int> res;
        for(int i=0; i<string_size-total_size_of_word+1; i++){
            string tmp = s.substr(i,total_size_of_word);
            bool possible = true;
            for(int j=0; j<total_size_of_word-wordsize+1;j+=wordsize){
                string word = tmp.substr(j,wordsize);
                if(!ump.count(word)){
                    possible = false;
                    break;
                }
                if(!ump2.count(word))
                    ump2[word] = 0;
                ump2[word]++;
            }
            if(possible){
                if(check(ump,ump2))
                    res.push_back(i);
            }
            ump2.clear();
        }
        return res;
    }
};