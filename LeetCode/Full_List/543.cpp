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
    int res;
    int height(TreeNode* root){
        if(!root)
            return 0;
        auto l = height(root->left);
        auto r = height(root->right);
        res = max(res,l+r);
        return (max(l,r)+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        height(root);
        return res;
    }
};