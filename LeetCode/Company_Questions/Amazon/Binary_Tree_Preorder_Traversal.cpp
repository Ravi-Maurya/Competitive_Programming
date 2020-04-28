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
    vector<int> preorderTraversal(TreeNode* root);
};
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    if(!A)
        return res;
    stack<TreeNode*> preorder;
    preorder.push(A);
    while(!preorder.empty()){
        while(A){
            res.push_back(A->val);
            if(A->right)
                preorder.push(A->right);
            A = A->left;
        }
        if(!preorder.empty()){
            A = preorder.top();
            preorder.pop();
        }
    }
    return res;
}