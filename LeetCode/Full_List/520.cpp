class Solution {
public:
    
    bool isBig(string& word, int i){
        for(int k=i; k<word.size(); k++){
            if(!(word[k] <='Z' && 'A'<=word[k]))
                return false;
        }
        return true;
    }
    
    bool isSmall(string& word, int i){
        for(int k=i; k<word.size(); k++){
            if(!(word[k] <='z' && 'a'<=word[k]))
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(word.size()==0)
            return true;
        if(word[0] <='Z' && 'A'<=word[0])
            return (isSmall(word,1) || isBig(word, 1));
        return isSmall(word,1);
    }
};