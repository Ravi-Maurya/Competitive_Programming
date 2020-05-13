#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* in_pre(vector<int>& preorder, int i, int j, unordered_map<int,int>& inorder, int& preorder_idx){// (preorder, 0, n-1, inorder, 0)
    if(j>i)
        return NULL;
    TreeNode* root = new TreeNode(preorder[preorder_idx++]);
    if(l==r)
        return root;
    int x = inorder[root->val];
    root->left = in_pre(preorder, i, x-1, inorder, preorder_idx);
    root->right = in_pre(preorder, x+1, j, inorder, preorder_idx);
    return root;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}