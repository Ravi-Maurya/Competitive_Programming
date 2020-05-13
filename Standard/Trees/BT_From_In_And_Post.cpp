#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* in_post(vector<int>& postorder, int i, int j, unordered_map<int,int>& inorder, int& postorder_idx){ // (postorder, 0, n-1, inorder, n-1)
    if(j>i)
        return NULL;
    TreeNode* root = new TreeNode(postorder[postorder_idx--]);
    if(l==r)
        return root;
    int x = inorder[root->val];
    root->right = in_post(postorder, x+1, j, inorder, postorder_idx);
    root->left = in_post(postorder, i, x-1, inorder, postorder_idx);
    return root;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}