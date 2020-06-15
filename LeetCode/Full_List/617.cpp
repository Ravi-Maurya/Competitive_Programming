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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)
            return t2;
        if(!t2)
            return t1;
        stack<pair<TreeNode*,TreeNode*>> st;
        st.push({t1,t2});
        while(!st.empty()){
            auto curr = st.top();st.pop();
            if(!curr.first || !curr.second)
                continue;
            curr.first->val += curr.second->val;
            if(!curr.first->left)
                curr.first->left = curr.second->left;
            else
                st.push({curr.first->left, curr.second->left});
            
            if(!curr.first->right)
                curr.first->right = curr.second->right;
            else
                st.push({curr.first->right , curr.second->right});
        }
        return t1;
    }
};