class Solution {
public:
    string removeDuplicateLetters(string text) {
        int n = text.size();
        vector<int> idx(26,-1);
        vector<bool> visited(26,false);
        for(int i=0; i<n; i++){
            idx[text[i]-'a'] = i;
        }
        deque<char> dq;
        for(int i=0; i<n; i++){
            while(!dq.empty() && !visited[text[i]-'a'] && text[i]<dq.back() && idx[dq.back()-'a']>i){
                visited[dq.back()-'a'] = false;
                dq.pop_back();
            }
            if(!visited[text[i]-'a']){
                visited[text[i]-'a']= true;
                dq.push_back(text[i]);
            }
        }
        string res = "";
        while(!dq.empty()){
            res += dq.front();
            dq.pop_front();
        }
        return res;
    }
};