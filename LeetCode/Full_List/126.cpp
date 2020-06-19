bool bfs(const string& start,const string& end,const vector<string>& tmp,unordered_map<string, vector<string>>& children){
    unordered_set<string> mapp(tmp.begin(), tmp.end()), current, next;
    current.insert(start);
    while (true){
        for (string word : current)
            mapp.erase(word);
        for (string word : current){
            string parent = word;
            for (int i = 0; i < word.size(); i++){
                char t = word[i];
                for (int j = 0; j < 26; j++){
                    word[i] = 'a' + j;
                    if (mapp.find(word) != mapp.end()){
                        next.insert(word);
                        children[parent].push_back(word);
                    }
                }
                word[i] = t;
            }
        }
        if (next.empty())
            return false;
        if (next.find(end) != next.end())
            return true;
        current.clear();
        swap(current, next);
    }
    return false;
}


void dfs(const string& start, const string& end, vector<string>& tmp, vector<vector<string>>& dict, unordered_map<string, vector<string>>& children) {
    if (start == end)
        dict.push_back(tmp);
    else{
        for(string word : children[start]){
            tmp.push_back(word);
            dfs(word, end, tmp, dict, children);
            tmp.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& dict) {
        vector<vector<string>> res;
        unordered_set<string> mapp(dict.begin(), dict.end());
        if(mapp.find(end)==mapp.end())
            return {};
        if(start==end){
            res.push_back({start});
            return res;
        }
        unordered_map<string, vector<string>> children;
        if (!bfs(start, end, dict, children))
            return {};
        vector<string> tmp;
        tmp.push_back(start);
        dfs(start, end, tmp, res, children);
        return res;
    }
};