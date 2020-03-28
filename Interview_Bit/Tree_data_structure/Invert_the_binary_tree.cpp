/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A)
        return NULL;
    A->left = invertTree(A->left);
    A->right = invertTree(A->right);
    TreeNode* tmp = A->left;
    A->left = A->right;
    A->right = tmp;
    return A;
}
