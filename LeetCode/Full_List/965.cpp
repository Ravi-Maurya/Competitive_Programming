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
    int check;
    bool preord(TreeNode* root){
        if(!root)
            return true;
        if(check!=root->val)
            return false;
        return (preord(root->left)&&preord(root->right));
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        check = root->val;
        return (preord(root->left)&&preord(root->right));
    }
};