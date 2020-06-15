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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                curr = curr->right;
            }
            curr = st.top();st.pop();
            sum += curr->val;
            curr->val = sum;
            
            curr = curr->left;
        }
        return root;
    }
};