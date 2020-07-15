class Solution {
public:
    string reverseWords(string s) {
        if(s == "")
            return "";
        stringstream SS(s);
        string res = "";
        while(SS>>s){
            res.insert(0," ");
            res.insert(0,s);
        }
        if(res.size())
            res.pop_back();
        return res;
    }
};