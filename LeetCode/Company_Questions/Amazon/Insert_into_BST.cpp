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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* add = new TreeNode(val);
        if(!root)
            return add;
        TreeNode* curr = root;
        TreeNode* tmp;
        while(curr){
            tmp = curr;
            if(val< curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(val < tmp->val)
            tmp->left = add;
        else
            tmp->right = add;
        return root;
    }
};