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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root)
            return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                auto curr = q.front();
                q.pop();
                if(size==1){
                    res.push_back(curr->val);
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                size -= 1;
            }
        }
        return res;
    }
};