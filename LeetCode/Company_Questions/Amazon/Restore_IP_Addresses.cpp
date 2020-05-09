class Solution {
public:
    void dfs(string prefix, int step, int start, vector<string> &res, string &s){
        if(step ==5 && prefix.size()-s.size()==4){
            prefix.pop_back();
            res.push_back(prefix);
            return;
        }
        if(step>5)
            return;
        for(int i=1; i<4; i++){
            int en = start + i;
            if(en>s.size() || (i>1 && s[start]=='0'))
                continue;
            auto segment = s.substr(start,i);
            int num = stoi(segment);
            if(num<0 || num>255)
                continue;
            dfs(prefix+segment+".", step+1, en, res,s);
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()==0)
            return {};
        vector<string> res;
        dfs("",1,0,res,s);
        return res;
    }
};