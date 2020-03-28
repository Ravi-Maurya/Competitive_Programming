/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* root){
    if(!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    int ht = 1+max(left,right);
    return ht;
}
int Solution::maxDepth(TreeNode* A) {
    return height(A);
}
