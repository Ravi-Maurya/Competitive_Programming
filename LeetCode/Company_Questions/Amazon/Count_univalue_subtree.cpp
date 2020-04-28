/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4
*/

class Solution{
    public:
    int count;
    bool is_valid(TreeNode* root, int val){
        if(!root)
            return true;
        if(!is_valid(root->left,root->val) || !is_valid(root->right,root->val))
            return false;
        count++;
        return root->val == val;
    }
    int countUnivalSubtrees(TreeNode* root){
        count = 0;
        is_valid(root,0);
        return count;
    }
};