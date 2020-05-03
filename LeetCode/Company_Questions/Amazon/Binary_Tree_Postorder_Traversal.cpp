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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> s;
        do{
            while(root){
                if(root->right)
                    s.push(root->right);
                s.push(root);
                root = root->left;
            }
            root = s.top();s.pop();
            if(root->right && !s.empty() && s.top()==root->right){
                s.pop();
                s.push(root);
                root = root->right;
            }
            else{
                res.push_back(root->val);
                root = NULL;
            }
        }while(!s.empty());
        return res;
    }
};