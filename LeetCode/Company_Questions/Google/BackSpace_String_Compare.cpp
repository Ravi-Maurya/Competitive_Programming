class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string res1 = "";
        string res2 = "";
        for(auto ch: S){
            if(ch == '#'){
                if(res1.size()>0)
                    res1.pop_back();
            }
            else
                res1.push_back(ch);
        }
        
        for(auto ch: T){
            if(ch == '#'){
                if(res2.size()>0)
                    res2.pop_back();
            }
            else
                res2.push_back(ch);
        }
        return res1==res2;
    }
};