struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
};

struct TrieNode* getNode(){
    struct TrieNode* root = new TrieNode;
    root->isEnd = false;
    for(int i=0 ; i<26; i++)
        root->child[i] = NULL;
    return root;
}

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = getNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string key) {
        struct TrieNode* curr = root;
        for(int i=0; i<key.size(); i++){
            int idx = key[i]-'a';
            if(!curr->child[idx])
                curr->child[idx] = getNode();
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(struct TrieNode* root, const char* key){
        for(int i =0; (key[i] && root); i++){
            if(key[i] != '.')
                root = root->child[key[i]-'a'];
            else{
                TrieNode* tmp = root;
                for(int j=0; j<26; j++){
                    root = tmp->child[j];
                    if(search(root,key+i+1))
                        return true;
                }
            }
        }
        return (root && root->isEnd);
    }
    
    bool search(string word) {
        return search(root, word.c_str());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */