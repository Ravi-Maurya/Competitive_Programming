class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int x1 = -1, x2 =-1;
        int res = words.size();
        for(int i=0; i<words.size();i++){
            if(word1 == words[i])
                x1 = i;
            else if(word2 == words[i])
                x2 = i;
            
            if(x1!=-1 && x2!=-1)
                res = min(res,abs(x1-x2));
        }
        return res;
    }
};