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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        stack<pair<TreeNode* , int>> st;
        st.push({root, root->val});
        while(!st.empty()){
            auto curr = st.top();st.pop();
            if(curr.first->left)
                st.push({curr.first->left, curr.first->left->val + curr.second});
            if(curr.first->right)
                st.push({curr.first->right, curr.first->right->val + curr.second});
            if(!curr.first->left && !curr.first->right && curr.second == sum)
                return true;
        }
        return false;
    }
};