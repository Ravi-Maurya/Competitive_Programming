class Solution {
public:
    string reverseWords(string A) {
        stringstream S;
        S<<A;
        string tmp = "";
        string word;
        while(S>>word){
            if(tmp.size()==0)
                tmp = word;
            else
                tmp = word+" "+tmp;
        }
        return tmp;
    }
};