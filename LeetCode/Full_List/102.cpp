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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> tmp;
        while(!q.empty()){
            int size = q.size();
            tmp.clear();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(tmp.size()>0)
                res.push_back(tmp);
        }
        return res;
    }
};