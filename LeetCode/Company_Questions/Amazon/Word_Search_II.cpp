class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        unordered_set<string> res;
        
        r = board.size();
        if(r <= 0)  return ans;
        c = board[0].size();
        if(c <= 0)  return ans;
        
        trie = new TrieNode();
        for(string word : words){
            createTrie(word);
        }
        
        vector<vector<bool>> visited(r, vector<bool>(c,false));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                dfs(board, res, visited, i, j, "");
            }
        }
        
        for(string word : res){
            ans.push_back(word);
        }
        return ans;
        
    }
    
    void dfs(vector<vector<char>>& board, unordered_set<string>& res,vector<vector<bool>>& visited, int i, int j, string str){
        if(i >= board.size() || i < 0 || j >=board[0].size() || j < 0 || visited[i][j])  
            return ;
        
        str += board[i][j];
        
        int state = find(str);
        if (state == 1)  res.insert(str);
        if (state == -1)  return;
        
        visited[i][j] = true;
        dfs(board, res, visited, i-1, j, str);
        dfs(board, res, visited, i+1, j, str);
        dfs(board, res, visited, i, j+1, str);
        dfs(board, res, visited, i, j-1, str);
        visited[i][j] = false;
    }
    private:
    static const int MAX = 26;
    struct TrieNode{
        TrieNode* next[MAX];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++)
                next[i] = nullptr;
        }
    };
    
    TrieNode* trie;
    
    int r;
    int c;
    
    void createTrie(string &str){
        const int len = str.length();
        TrieNode *p = trie, *q;
        for(int i = 0; i < len; i++){
            int id = str[i]-'a';
            if(p->next[id] == nullptr){
                q = new TrieNode();
                if(i == len-1)  q->isEnd = true;
                p->next[id] = q;
                p = q;
            }
            else{
                p = p->next[id];
            }
        }
        p->isEnd = true;
        
    }
    int find(const string &str){ // 0 exists but not exactly is, 1 exactly is, -1 not exist at all
        int len = str.length();
        TrieNode* p = trie;
        bool exist = false;
        for(int i = 0; i < len; i++){
            int id = str[i]-'a';
            p = p->next[id];
            if(!p){
                return -1; 
            }
            exist = true;
        }
        return p->isEnd ? 1 : 0;
    }
};