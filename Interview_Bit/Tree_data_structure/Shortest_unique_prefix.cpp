const int SIZE = 26;
struct trie{
    trie* child[SIZE];
    int frequency;
};

trie* getNode(){
    trie* tmp = new trie();
    tmp->frequency = 1;
    for(int i=0;i<SIZE;i++)
        tmp->child[i] = NULL;
    return tmp;
}

void insert(trie* root, string key){
    trie* tmp = root;
    for(int i=0;i<key.length();i++){
        int idx = key[i]-'a';
        if(!tmp->child[idx])
            tmp->child[idx] = getNode();
        else
            (tmp->child[idx]->frequency)++;
        tmp = tmp->child[idx];
    }
}

string search(trie* root, string key){
    string s = "";
    trie* tmp = root;
    for(int i=0;i<key.length();i++){
        int idx = key[i]-'a';
        if(!tmp->child[idx])
            return s;
        if(tmp->child[idx]->frequency == 1){
            s += key[i];
            return s;
        }
        else{
            s += key[i];
            tmp = tmp->child[idx];
        }
    }
    return s;
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> res;
    trie* root = getNode();
    root->frequency = 0;
    for(auto word:A)
        insert(root,word);
    for(auto word:A){
        res.push_back(search(root,word));
    }
    return res;
}
