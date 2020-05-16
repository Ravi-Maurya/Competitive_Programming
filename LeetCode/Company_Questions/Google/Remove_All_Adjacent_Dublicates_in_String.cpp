class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stck;
        int i = 1, n = S.size();
        if(!n)
            return S;
        stck.push(S[0]);
        while(i<n){
            while(i<n && !stck.empty() && stck.top()==S[i]){
                stck.pop();
                i++;
            }
            if(i<n)
                stck.push(S[i]);
            i++;
        }
        string res = "";
        int k = stck.size();
        res.resize(k);
        while(!stck.empty()){
            res[k-1] = stck.top();
            stck.pop();
            k--;
        }
        return res;
    }
};