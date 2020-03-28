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
    if(left==0 && right==0)
        return 1;
    if(left==0)
        return 1+right;
    if(right==0)
        return 1+left;
    int ht = 1+min(left,right);
    return ht;
}
int Solution::minDepth(TreeNode* A) {
    return height(A);
}
