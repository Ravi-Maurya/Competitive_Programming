class Solution {
public:
    vector<string> letterCombinations(string A) {
        string table[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> res;
        if(!A.size())
            return res;
        queue<string> q;
        q.push("");
        int number[A.size()];
        int i =0;
        for(auto x:A){
            number[i] = (int)(x-'0');
            i++;
        }
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(s.length()==A.size())
                res.push_back(s);
            else{
                for(auto letter:table[number[s.length()]])
                    q.push(s+letter);
            }
        }
        return res;
    }
};