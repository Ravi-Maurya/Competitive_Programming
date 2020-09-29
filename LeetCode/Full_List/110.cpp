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
    bool helper(TreeNode* root, int& h){
        if(!root){
            h = -1;
            return true;
        }
        int l, r;
        if(helper(root->left,l) && helper(root->right, r) && abs(l-r)<2){
            h = max(l,r) + 1;
            return true;
        }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int h;
        return helper(root,h);
    }
};