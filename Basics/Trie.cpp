#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

const int size = 26;

struct TrieNode{
    struct TrieNode* child[size];
    bool isEnd;
};

struct TrieNode* getNode(){
    struct TrieNode* root = new TrieNode;
    root->isEnd = false;
    for(int i=0 ; i<size; i++)
        root->child[i] = NULL;
    return root;
}

void insert(struct TrieNode* root, string key){
    struct TrieNode* curr = root;
    for(int i=0; i<key.size(); i++){
        int idx = key[i]-'a';
        if(!curr->child[idx])
            curr->child[idx] = getNode();
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

bool search(struct TrieNode* root, string key){
    struct TrieNode* curr = root;
    for(int i=0; i<key.size(); i++){
        int idx = key[i]-'a';
        if(!curr->child[idx])
            return false;
        curr = curr->child[idx];
    }
    return (curr!=NULL && curr->isEnd);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}