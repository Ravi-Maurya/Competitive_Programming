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
    vector<string> res;
    void dfs(TreeNode* root, string s){
        if(!root)
            return;
        if(root && !root->left && !root->right){
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        string curr = to_string(root->val);
        s += curr;
        s.push_back('-');
        s.push_back('>');
        dfs(root->left,s);
        dfs(root->right,s);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        dfs(root,s);
        return res;
    }
};