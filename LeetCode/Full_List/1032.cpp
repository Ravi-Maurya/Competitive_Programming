class StreamChecker {
public:
    
    struct TrieNode{
        vector<TrieNode*> tree;
        bool is_word;
        TrieNode(){
            tree = vector<TrieNode*>(26,NULL);
            is_word = false;
        }
    };
    
    TrieNode* root;
    string word;
    
    void insert(vector<string>& words){
        for(string s:  words){
            reverse(s.begin(),s.end());
            TrieNode* tmp = root;
            for(auto ch: s){
                if(!tmp->tree[ch-'a'])
                    tmp->tree[ch-'a'] = new TrieNode();
                tmp = tmp->tree[ch-'a'];
            }
            tmp->is_word = true;
        }
    }
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        word = "";
        insert(words);
    }
    
    bool query(char letter) {
        word += letter;
        TrieNode* tmp = root;
        for(int i=word.size()-1; i>=0 && tmp; i--){
            tmp = tmp->tree[word[i]-'a'];
            if(tmp && tmp->is_word)
                return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */