class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(auto& ch:address){
            if(ch=='.')
                res += "[.]";
            else
                res += ch;
        }
        return res;
    }
};