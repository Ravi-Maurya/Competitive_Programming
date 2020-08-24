/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int res = 0;
        if(root->left && !root->left->left && !root->left->right)
            res += root->left->val;
        res += solve(root->left);
        res += solve(root->right);
        return res;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 0;
        return solve(root);
    }
};