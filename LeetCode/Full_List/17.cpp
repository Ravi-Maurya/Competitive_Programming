class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string phone[10] = {"0", "1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.size();
        if(n==0)
            return {};
        vector<string> res;
        vector<int> number(n);
        for(int i=0;i<n;i++)
            number[i] = digits[i]-'0';
        queue<string> q;
        q.push("");
        while(!q.empty()){
            string curr = q.front();q.pop();
            if(curr.size() == n)
                res.push_back(curr);
            else{
                for(auto v: phone[number[curr.size()]])
                    q.push(curr+v);
            }
        }
        return res;
    }
};