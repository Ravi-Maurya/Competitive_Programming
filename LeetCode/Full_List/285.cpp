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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right){
            p = p->right;
            while(p->left)
                p = p->left;
            return p;
        }
        stack<TreeNode*> st;
        int res = INT_MIN;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();st.pop();
            if(res == p->val)
                return root;
            res = root->val;
            root = root->right;
        }
        return nullptr;
    }
};