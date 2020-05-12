#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 vector<vector<int>> levelorder(TreeNode* root){
     if(!root)
        return {};
    queue<TreeNode*> bfs;
    bfs.push(root);
    vector<vector<int>> res;
    while(!bfs.empty()){
        int size = bfs.size();
        vector<int> tmp;
        while(size--){
            auto curr = bfs.front();
            bfs.pop();
            tmp.push_back(curr->val);
            if(curr->left)
                bfs.push(curr->left);
            if(curr->right)
                bfs.push(curr->right);
        }
        res.push_back(tmp);
    }
    return res;
 }

vector<int> postorder(TreeNode* root){
    if(!root)
        return {};
    stack<TreeNode*> post;
    vector<int>res;
    do{
        while(root){
            if(root->right)
                post.push(root->right);
            post.push(root);
            root = root->left;
        }
        root = post.top();post.pop();
        if(root->right && !post.empty() && post.top()==root->right){
            post.pop();
            post.push(root);
            root = root->right;
        }
        else{
            res.push_back(root->val);
            root = NULL;
        }
    }while(!post.empty());
    return res;
}

vector<int> preorder(TreeNode* root){
    if(!root)
        return {};
    stack<TreeNode*> pre;
    pre.push(root);
    vector<int>res;
    while(!pre.empty()){
        while(root){
            res.push_back(root);
            if(root->right)
                pre.push(root->right);
            root = root->left;
        }
        if(!pre.empty()){
            root = pre.top();pre.pop();
        }
    }
    return res;
}

vector<int> inorder(TreeNode* root){
    if(!root)
        return {};
    stack<TreeNode*> in;
    in.push(root);
    vector<int>res;
    while(root || !in.empty()){
        while(root){
            in.push(root);
            root = root->left;
        }
        root = in.top();in.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}