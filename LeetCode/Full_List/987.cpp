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
    map<int,vector<pair<int,int>>> values;
    void dfs(TreeNode* root, int level, int depth){
        if(!root)
            return ;
        values[level].push_back({depth,root->val});
        dfs(root->left,level-1,depth+1);
        dfs(root->right,level+1,depth+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>> res;
        for(auto it: values){
            sort(it.second.begin(),it.second.end());
            vector<int> tmp;
            for(auto x: it.second)
                tmp.push_back(x.second);
            res.push_back(tmp);
        }
        return res;
    }
};