#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int lcs_bst(TreeNode* root, TreeNode* a, TreeNode* b){
    if(!root || !a || !b)
        return -1;
    if((a->val <= root->val && root->val <= b->val || a->val >= root->val && root->val >= b->val))
        return root->val;
    if(a->val > root->val && b->val && root->val)
        return lcs_bst(root->right,a,b);
    return lcs_bst(root->left, a, b);
}

TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b){
    if(!root)
        return NULL;
    if(root == a || root == b)
        return root;
    auto left = lca(root->left, a, b);
    auto right = lca(root->right, a, b);
    if(!left && !right)
        return NULL;
    if(left && right)
        return root;
    return left?left:right;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}