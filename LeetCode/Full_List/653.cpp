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
    unordered_set<int> ust;
    
    bool traverse(TreeNode* root, int k){
        if(!root)
            return false;
        if(ust.count(k-root->val))
            return true;
        ust.insert(root->val);
        if(traverse(root->left,k))
            return true;
        return traverse(root->right,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        ust.clear();
        return traverse( root, k);
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root,  k);
    }
    
    bool dfs(TreeNode* root,  TreeNode* cur, int k){
        if(cur == NULL)
            return false;
        if(search(root, cur, k - cur->val))
            return true;
        if(dfs(root, cur->left, k))
            return true;
        return dfs(root, cur->right, k);
    }
    
    bool search(TreeNode* root, TreeNode *cur, int value){
        if(root == NULL)
            return false;
        if(root->val == value && root!=cur)
            return true;
        if(root->val<value && search(root->right, cur, value))
            return true;
        return ((root->val > value) && search(root->left, cur, value));
    }
};