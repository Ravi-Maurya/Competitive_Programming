#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert_node(TreeNode* root, int val){
    if(!root)
        return new TreeNode(val);
    if(val< root->val)
        root->left = insert_node(root->left, val);
    else
        root->right = insert_node(root->right, val);
    return root;
}

TreeNode* predecessor(TreeNode* root){
    while(root->right)
        root = root->right;
    return root;
}

void delete_node(TreeNode* root, int val){
    if(!root)
        return;
    if(val<root->val)
        delete_node(root->left, val);
    else if (val>root->val)
        delete_node(root->right, val);
    else{
        if(!root->left && !root->right){
            delete root;
            root = nullptr;
        }
        else if(root->left && root->right){
            TreeNode* pred = predecessor(root->left);
            root->val = pred->val;
            delete_node(root->left,pred->val);
        }
        else{
            TreeNode* child = root->left?root->left:root->right;
            TreeNode* curr = root;
            root = child;
            delete curr;
        }
    }
}

void inorder_predecessor(TreeNode* root, TreeNode*& res, int val){
    if(!root){
        res = nullptr;
        return;
    }
    if(root->val == val)
        if(root->left)
            res = predecessor(root->left);
    else if(val<root->val)
        inorder_predecessor(root->left,res,val);
    else{
        res = root;
        inorder_predecessor(root->right,res,val);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}