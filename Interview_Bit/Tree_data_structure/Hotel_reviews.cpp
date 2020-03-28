const int SIZE = 26;
struct trie{
    trie* child[SIZE];
    bool isLeaf;
};

trie* getNode(){
    trie* tmp = new trie();
    tmp->isLeaf = false;
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
        tmp = tmp->child[idx];
    }
    tmp->isLeaf = true;
}

bool search(trie* root, string key){
    trie* tmp = root;
    for(int i=0;i<key.length();i++){
        int idx = key[i]-'a';
        if(!tmp->child[idx])
            return false;
        tmp = tmp->child[idx];
    }
    return (tmp!=NULL && tmp->isLeaf);
}

void convert(string& s){
    for(int i=0;i<s.size();i++)
        if(s[i]=='_')
            s[i] = ' ';
    return;
}

bool compare(const pair<int,int>& a,const pair<int,int>& b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> res;
    vector<pair<int,int>> tmp;
    trie* root = getNode();
    string word;
    stringstream SS;
    convert(A);
    SS<<A;
    while(SS>>word)
        insert(root,word);
    int count;
    for(int i=0;i<B.size();i++){
        convert(B[i]);
        SS.clear();
        SS<<B[i];
        count = 0;
        while(SS>>word)
            if(search(root,word))
                count++;
        tmp.push_back({count,i});
    }
    sort(tmp.begin(),tmp.end(),compare);
    for(int i=0;i<B.size();i++)
        res.push_back(tmp[i].second);
    return res;
}
