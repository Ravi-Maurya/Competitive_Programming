/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int V;
    void helper(TreeNode* root, int mx, int mn){
        if(!root)
            return;
        if(root->val > mx)
            mx = root->val;
        if(root->val < mn)
            mn = root->val;
        if(mx-mn > V)
            V = mx-mn;
        helper(root->left,mx,mn);
        helper(root->right, mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        V = INT_MIN;
        helper(root,0,INT_MAX);
        return V;
    }
};