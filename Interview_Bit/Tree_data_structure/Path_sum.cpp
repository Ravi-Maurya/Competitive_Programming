/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    if(!A)
        return 0;
    if(!A->left && !A->right)
        return (A->val == B)?1 : 0;
    int left = hasPathSum(A->left,B - A->val);
    int right = hasPathSum(A->right,B - A->val);
    free(A->left);
    free(A->right);
    return (left || right);
}
