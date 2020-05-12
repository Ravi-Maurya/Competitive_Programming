class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        TrieNode* children[26];
        bool isend;
    };
    TrieNode* root;
    TrieNode* getNode(){
        TrieNode* curr = new TrieNode();
        for(int i=0; i<26; i++){
            curr->children[i] = NULL;
        }
        curr->isend = false;
        return curr;
    }
    Trie() {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            if(!curr->children[idx])
                curr->children[idx] = getNode();
            curr = curr->children[idx];
        }
        curr->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            if(!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return (curr!=NULL && curr->isend);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            if(!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return (curr!=NULL || curr->isend);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */