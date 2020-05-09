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
    vector<int> leftSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root)
            return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool selected_left = false;
            while(size--){
                auto curr = q.front();
                q.pop();
                if(!selected_left){
                    res.push_back(curr->val);
                    selected_left = true;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return res;
    }
};