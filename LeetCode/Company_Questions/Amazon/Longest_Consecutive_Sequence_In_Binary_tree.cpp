/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode* root, int curr_length, int expected, int& res){
    if(!root)
        return;
    if(root->val == expected)
        curr_length++;
    else
        curr_length = 1;
    res = max(res,curr_length);
    helper(root->left, curr_length, root->val + 1, res);
    helper(root->right, curr_length, root->val + 1, res);
}
int Solution::solve(TreeNode* root) {
    if(!root)
        return 0;
    int res = 0;
    helper(root,0,root->val,res);
    return res;
}
