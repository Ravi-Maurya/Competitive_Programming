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
    void dfs(int& res, TreeNode* root, int curr){
        if(!root)
            return;
        if(!root->left && !root->right){
            res += (curr*10 + root->val);
            return;
        }
        dfs(res, root->left, curr*10 + root->val);
        dfs(res, root->right, curr*10 + root->val);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(res, root, 0);
        return res;
    }
};