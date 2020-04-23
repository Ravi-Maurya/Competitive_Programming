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
    long int mx;
    const long int mn = INT_MIN;
    long int rec(TreeNode* root){
        if(!root)
            return mn;
        long int i = root->val;
        long int l = rec(root->left);
        long int r = rec(root->right);
        mx = max(mx, max({i,l,r,i+l,i+r,i+l+r}));
        return max({i,i+l,i+r});
    }
public:
    int maxPathSum(TreeNode* root) {
        mx = mn;
        rec(root);
        return mx;
    }
};