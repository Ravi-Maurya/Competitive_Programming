/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool check(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2)
        return true;
    else if(root1 && root2)
        return ((root1->val == root2->val) && check(root1->left,root2->left) && check(root1->right,root2->right));
    else
        return false;
}
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return check(A,B);
}
