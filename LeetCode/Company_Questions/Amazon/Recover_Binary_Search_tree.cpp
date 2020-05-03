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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *one = NULL, *two = NULL;
        dfs(root, prev, one, two);
        swap(one->val, two->val);
    }
    
    void dfs(TreeNode* curr, TreeNode* &prev, TreeNode* &one, TreeNode* &two){
        if(!curr) return;
        dfs(curr->left, prev, one, two);
        if(prev && curr->val < prev->val){
            if(!one) one = prev;
            two = curr;
        }
        prev = curr;
        dfs(curr->right, prev, one, two);
    }
};