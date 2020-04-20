#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

const int size = 26;

struct TrieNode{
    struct TrieNode* child[size];
    bool isEnd;
    vector<int> index;
};

struct TrieNode* getNode(){
    struct TrieNode* root = new TrieNode;
    root->isEnd = false;
    root->index = {};
    for(int i=0 ; i<size; i++)
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<string> arr(n);
        struct TrieNode* root = getNode();
        for(int i=0;i<n;i++){
            cin>>arr[i];
            insert(root, arr[i], i);
        }
        string query;
        cin>>query;
        vector<vector<int>> res = search(root, query);
        vector<set<string>> ans = convert(res,arr);
        for(int i=0; i<ans.size();i++){
            for(auto idx: ans[i]){
                printf("%s ",idx.c_str());
            }
            printf("\n");
        }
        for(int i=ans.size(); i<query.size();i++)
            printf("0\n");
    }
    return 0;
}