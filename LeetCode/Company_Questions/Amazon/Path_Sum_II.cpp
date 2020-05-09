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
    void dfs(vector<vector<int>>& res, TreeNode* root, int& sum, int curr_sum, vector<int>& tmp){
        if(!root)
            return;
        if(sum == curr_sum+root->val && !root->left && !root->right){
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        dfs(res,root->left,sum,curr_sum + root->val, tmp);
        dfs(res,root->right,sum,curr_sum + root->val, tmp);
        tmp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, root, sum, 0, tmp);
        return res;
    }
};