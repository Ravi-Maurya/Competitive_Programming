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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;
        stack<TreeNode*> s;
        while(!s.empty() || curr){
            while(curr){
                s.push(curr);
                curr=  curr->right;
            }
            curr = s.top();
            s.pop();
            sum += curr->val;
            curr->val = sum;
            curr = curr->left;
        }
        return root;
    }
};