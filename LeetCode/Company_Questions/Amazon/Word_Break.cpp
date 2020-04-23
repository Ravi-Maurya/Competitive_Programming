class Solution {
public:
    bool wordBreak(string A, vector<string>& B) {
    unordered_set<string> s;
    int n = A.size();
    for(auto it:B)
        s.insert(it);
    vector<int> tmp(n+1,0);
    tmp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            string t = A.substr(i, j-i+1);
            if(s.find(t)!=s.end() && tmp[j+1] == 1){
                tmp[i] = 1;
                break;
            }
        }
    }
    return tmp[0];
    }
};