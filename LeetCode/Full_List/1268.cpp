
struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
    vector<int> index;
};

struct TrieNode* getNode(){
    struct TrieNode* root = new TrieNode;
    root->isEnd = false;
    root->index = {};
    for(int i=0 ; i<26; i++)
        root->child[i] = NULL;
    return root;
}

void insert(struct TrieNode* root, string key, int ix){
    struct TrieNode* curr = root;
    for(int i=0; i<key.size(); i++){
        int idx = key[i]-'a';
        if(!curr->child[idx])
            curr->child[idx] = getNode();
        curr = curr->child[idx];
        curr->index.push_back(ix);
    }
    curr->isEnd = true;
    curr->index.push_back(ix);
}

vector<vector<int>> search(struct TrieNode* root, string key){
    vector<vector<int>> res;
    struct TrieNode* curr = root;
    for(int i=0; i<key.size(); i++){
        int idx = key[i]-'a';
        if(!curr->child[idx])
            return res;
        curr = curr->child[idx];
        res.push_back(curr->index);
    }
    return res;
}

vector<set<string>> convert(vector<vector<int>>& res, vector<string>& arr){
    vector<set<string>> ans(res.size());
    for(int i=0;i<res.size();i++){
        for(int j=0; j<res[i].size();j++){
            ans[i].insert(arr[res[i][j]]);
        }
    }
    return ans;
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        auto root = getNode();
        for(int i=0; i<n; i++)
            insert(root,products[i],i);
        vector<vector<int>> res = search(root,searchWord);
        vector<set<string>> ans = convert(res,products);
        vector<vector<string>> give(searchWord.size());
        for(int i=0;i<ans.size();i++){
            for(auto& s: ans[i]){
                give[i].push_back(s);
                if(give[i].size()==3)
                    break;
            }
        }
        return give;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix = "";
        // keep adding a character to the prefix
        // find the next three words in the sorted products which have prefix
        for (char c : searchWord) {
            prefix += c;
            vector<string> suggested;
            vector<string>::iterator it = lower_bound(products.begin(), products.end(), prefix);
            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                string& s = *(it + i);
                if (s.find(prefix) != 0) 
                    break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};