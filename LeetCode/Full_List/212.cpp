class Solution {
public:
    struct TrieNode{
        struct TrieNode* child[26];
        bool isEnd;
        int idx;
        TrieNode(){
            isEnd = false;
            idx = -1;
            for(int i=0; i<26; i++)
                child[i] = nullptr;
        }
    };
    
    TrieNode* root;
    vector<string> res;
    
    void addWord(string key, int v) {
        struct TrieNode* curr = root;
        for(int i=0; i<key.size(); i++){
            int idx = key[i]-'a';
            if(!curr->child[idx])
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }
        curr->isEnd = true;
        curr->idx = v;
    }
    
    void dfs(TrieNode* parent, vector<vector<char>>& board, int i, int j , vector<string>& words){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            if(parent->isEnd && parent->idx!=-1){
                res.push_back(words[parent->idx]);
                parent->idx=-1;
            }
            return;
        }
        if(parent->isEnd && parent->idx!=-1){
            res.push_back(words[parent->idx]);
            parent->idx=-1;
        }
        for(int k=0; k<26; k++){
            if(parent->child[k]!=nullptr && (k == (int)(board[i][j]-'a'))){
                board[i][j] = '.';
                dfs(parent->child[k],board,i+1,j,words);
                dfs(parent->child[k],board,i,j+1,words);
                dfs(parent->child[k],board,i-1,j,words);
                dfs(parent->child[k],board,i,j-1,words);
                board[i][j] = (char)(k+'a');
            }
        }
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(int i=0; i<words.size(); i++)
            addWord(words[i],i);
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size();j++)
                dfs(root,board,i,j,words);
        return res;
    }
};